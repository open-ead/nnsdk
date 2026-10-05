# Contribution Guidelines

## Development

To build and run checks, please install:

- [task](https://taskfile.dev) for running commands.
- CMake (check the version requirement in CMakeLists.txt) and Ninja.

Please run `task configure` before running the other commands.
If you want to configure for a specific version you can use the `NN_VER` env variable which is by default set to
`1.0.0`:

```shell
NN_VER=4.4.0 task configure
```

Workflows:

- Run `task configure` to configure the CMake projects.
- Run `task build` to build and run tests.
- Run `task check` to check formatting and clang-tidy issues. `task fix` formats the files.
- Run `task pr` to run the same checks that the PR runs.
  It's a good idea to always run this one before you open or update a PR.

If there are errors after merging upstream updates, run `task clean`
to clean CMake cache and update your local dependencies. If the error
persists, please ask for help in Discord.

## Repo Structure

- `/include`: headers for nnSdk and nnSdk C bindings. Right now, we don't decompile
  the shared SDK library (nnSdk), as the games usually link it dynamically.
- `/lib/*`: One CMake subdirectory for each library target that gets statically linked into the game.
- `/test`: Test projects.

## NN Header Structure

The headers in `/include/nn` should follow these rules:

- Use `nn/foo.h` and `nn/foo/` for the namespace `nn::foo` and any sub-namespace.
    - Put things that are in the `nn::foo::detail` namespace into one of the `nn/foo/detail/foo_Something.h` headers.
    - Put everything that is not `detail` in one of the `nn/foo/foo_Something.h` headers,
      including things in other sub-namespaces like `nn::foo::subnamespace`.
    - Put things that don't really fit in any `foo_Something.h` in `nn/foo.h`. This file should also
      re-export every `nn/foo/foo_Something.h`, but not the `detail` headers.
- For inter-module dependencies, prefer including the exact `nn/foo/foo_Something.h` instead of
  the umbrella `nn/foo.h`.
- If you need to add a "placeholder type" (i.e. a type whose symbol is referenced in something
  you are adding, but you don't need the definition of the type), put a placeholder definition
  like `struct Foo {}; // TODO` in the "right file", which is either `nn/foo/foo_Xy.h` or `nn/foo.h`.
  You can then include this header, or forward-declare the type, wherever you need it.
  Do not add only a forward declaration as that makes it harder to track all the placeholders.

## Sub-module Structure

Each SDK module is its own CMake subdirectory at `/lib/*` and has its own `include` and `src`
directories. The header rules above also apply to each module.

## C Bindings

The SDK exports C bindings for third-party libraries such as `curl` to call. These headers
are at `/include/nnc`. These can be either generated or hand-written. If external C code
needs to access the fields of a type, then Nintendo hand-wrote the binding for that type.
Otherwise, the type is an opaque type that has the same size and alignment as the C++ type.

The C binding files have the same structure as the C++ headers, i.e. one `nnc/foo/foo_Xy.h`
per `nn/foo/foo_Xy.h`. If a file includes any `@nncbindgen` comment, it will automatically be
picked up by bindgen. If a binding needs to be hand-written, then the corresponding C++
header must not have `@nncbindgen` comments; otherwise the hand-written changes would be overwritten.

To regenerate the nnc folder, use `task cbindgen`. If is the first time run `task configure`

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
// This generates:
// typedef union nnfooFooBar { .. } nnfooFooBar;
// typedef enum nnfooFooBarBiz { nnfooFooBarBiz_A, nnfooFooBarBiz_B } nnfooFooBarBiz;
// nnResult nnfooFooBarCreate(nnfooFooBar* this_, nnfooFooBarBiz b);

// Struct/class can also be typedef'd
// @nncbindgen typedef int;
class X {
    int x;
};
// This generates: typedef int nnfooX;

// @nncbindgen
enum Abc { Abc_A, Abc_B };
// This generates: typedef enum nnfooAbc { nnfooAbc_A, nnfooAbc_B } nnfooAbc;

// For enum class, the enum name is prefixed to each enumerator
// @nncbindgen
enum class Xyz { A, B };
// This generates: typedef enum nnfooXyz { nnfooXyz_A, nnfooXyz_B } nnfooXyz;

// @nncbindgen
FooBar* FooTheBar(FooBar* foo, Abc, int);
// This generates: nnfooFooBar* nnfooFooTheBar(nnfooFooBar* foo, nnfooAbc, int);

// The inferred namespace is the last 'namespace' line seen.
// If that is incorrect, specify the fully-qualified type name.
// @nncbindgen
nn::Result FooTheXyz(Xyz);
// This generates: nnResult nnfooFooTheXyz(nnfooXyz);

// Use 'rename' for overloads
// @nncbindgen(rename=FooTheXyzWithTwo)
nn::Result FooTheXyz(Xyz, Xyz);
// This generates: nnResult nnfooFooTheXyzWithTwo(nnfooXyz, nnfooXyz);

// Use 'define' for external type definitions
// @nncbindgen define struct Xyz*
// @nncbindgen define enum Abc
nn::Result FooTheXyz(Xyz*, Abc);
// This generates: nnResult nnfooFooTheXyzWithTwo(struct Xyz*, enum Abc);

}
```

See the `nn/ssl/` headers for more examples.

## PR Rules

Please use English for PRs and squash your branch into one commit.
Keep PRs reasonably sized to get them reviewed faster. If there are multiple
things in the same PR, consider splitting them into multiple PRs.

If it isn't straightforward from the usage or binary why something must be added,
please include an explanation or source.
