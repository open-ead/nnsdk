# Contribution Guidelines

## Development

For running commands please install [task](https://taskfile.dev), CMake, Ninja and Clang/LLVM.
The Clang/LLVM toolchain version should match the [image used in the PR](https://github.com/open-ead/containers/blob/main/ubuntu-builder/Dockerfile)

Workflows:
- Run `task configure` to configure the CMake projects
- Run `task build` to run build and tests.
- Run `task check` to check formatting and clang-tidy issues. `task fix` formats the files
- Run `task pr` to run the same checks that the PR runs.
  It's a good idea to always run this one before you open or update a PR.

## Repo structure

- `/include`: headers for nnSdk and nnSdk C bindings. Right now, we don't decompile
  the shared SDK library (nnSdk), as the games usually link it dynamically.
- `/lib/*`: One CMake subdirectory for each library target that gets statically linked into the game
- `/test`: Test projects

## NN header structure

The headers in `/include/nn` should follow these rules:

- Use `nn/foo.h` and `nn/foo/` for the namespace `nn::foo` and any sub-namespaces.
  - Put things that are in the `nn::foo::detail` namespace into one of `nn/foo/detail/foo_Something.h` headers.
  - Put everything that is not `detail` in one of `nn/foo/foo_Something.h` headers even if it has
    a sub-namespace.
  - Put things that don't really fit in any `foo_Something.h` in `nn/foo.h`. This file should also
    re-export every `nn/foo/foo_Something.h`, but not the `detail` headers.
- For inter-module dependencies, prefer including the exact `nn/foo/foo_Something.h` instead of
  the everything `nn/foo.h`
- If you need to add a "placeholder type" (i.e. a type whose symbol is referenced in something
  you are adding, but you don't need the definition of the type), put a placeholder definition
  like `struct Foo {}; // TODO` in the "right file", which is either `nn/foo/foo_Xy.h` or `nn/foo.h`.
  You can then include this header where you need to reference this symbol or forward declare it.
  Do not add only forward declaration as that makes it harder to track all the placeholders.

## Sub-module structure

Each SDK module is its own CMake subdirectory at `/lib/*` and has its own `include` and `src`
directories. The same rules for the SDK header apply to each module.

## C Bindings

The SDK exports C bindings for 3rd party libraries such as `curl` to call. These headers
are at `/include/nnc`. These can either be generated, or hand-written. If external C code
needs to access the fields of a type, then Nintendo hand wrote the
binding for that type. Otherwise, the type is an opaque type that has the same size and alignment
as the C++ type.

The C binding files have the same structure as the C++ headers, i.e. one `nnc/foo/foo_Xy.h`
per `nn/foo/foo_Xy.h`. If a file includes any `@nncbindgen` comment, it will automatically be
included in the bindgen. If a binding needs to be hand-written, then the corresponding C++
header must not have `@nncbindgen` comments, otherwise the changes would be overriden.

To generate a binding, simply add `// @nncbindgen` above the item:

```cpp
namespace nn::foo {

// @nncbindgen
class FooBar {
    // @nncbindgen(memberof=FooBar)
    enum class Biz { A, B };
    // @nncbindgen(memberof=FooBar)
    nn::Result Create(Biz* b);
};
// this generates:
// typedef union nnfooFooBar { .. } nnfooFooBar;
// typedef enum nnfooFooBarBiz { nnfooFooBarBiz_A, nnfooFooBarBiz_B } nnfooFooBarBiz;
// nnResult nnfooFooBarCreate(nnfooFooBar* this_, nnfooFooBarBiz b);

// struct/class can also be typedef'd
// @nncbindgen typedef int;
class X {
    int x;
};
// this generates: typedef nnfooX int;

// @nncbindgen
enum Abc { Abc_A, Abc_B };
// this generates: typedef enum nnfooAbc { nnfooAbc_A, nnfooAbc_B } nnfooAbc;

// For enum class, the class name is also added
// @nncbindgen
enum class Xyz { A, B };
// this generates: typedef enum nnfooXyz { nnfooXyz_A, nnfooXyz_B } nnfooXyz;


// @nncbindgen
FooBar* FooTheBar(FooBar* foo, Abc, int);
// this generates: nnfooFooBar* nnfooFooTheBar(nnfooFooBar* foo, nnfooAbc, int);

// the inferred namespace is the last 'namespace' line seen,
// if that is incorrect, specify the fully-qualified type name
// @nncbindgen
nn::Result FooTheXyz(Xyz);
// this generates: nnResult nnfooFooTheXyz(nnfooXyz);

// use 'rename' for overloads
// @nncbindgen(rename=FooTheXyzWithTwo)
nn::Result FooTheXyz(Xyz, Xyz);
// this generates: nnResult nnfooFooTheXyzWithTwo(nnfooXyz, nnfooXyz);

}
```

See the ssl headers for more examples.


## PR Rules

Please use English for PRs and squash your branch into one commit.
Keep the PR reasonably sized to get them reviewed faster. If there are mutiple
things in the same PR, considering splitting them into multiple PRs.

If it isn't straightforward from the usage or binary why something must be added,
please include an explanation or source for member or function names.
