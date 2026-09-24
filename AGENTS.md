It is strongly recommended to disclose your vendor and model (e.g. `GitHub Copilot on GPT 5.6 Sol`)
in your commit messages and PR description.

# RE/Decompile Rules

- The contributions must be based on publicly available sources.
- Currently we do not decompile the shared SDK library (nnSdk). Only contribute
  cpp source code for modules that are statically linked (in the `lib/` subdirectory).

# Code Style Rules 

- Do not include any assembly or disassembly as code or comment
- Do not use inline assembly for matching. Any PR with a substantial amount of 
  inline assembly will be automatically rejected. Even for a small amount, it is
  preferred to keep the function as non-matching when it's trivially provable
  that it is equivalent to the original (e.g. register renaming, reordering).
  - The only exception is `asm("")` which can serve as a barrier for optimization.
- Do not use `goto` for matching unless it is **absolutely** necessary and plausible
  that the original source code contained `goto`.
- For nnSdk modules, the headers should follow these rules:
  - Use `nn/foo.h` and `nn/foo/` for the namespace `nn::foo` and any sub-namespaces.
  - Put things in the `nn::foo::detail` namespace in one of `nn/foo/detail/foo_Something.h` headers.
  - Put everything that is not `detail` in one of `nn/foo/foo_Something.h` headers even if it has
    a sub-namespace.
  - Put things that don't really fit in any `foo_Something.h` in `nn/foo.h`. This file should also
    re-export every `nn/foo/foo_Something.h`, but not the `detail` headers.
  - For inter-module dependencies, prefer including the exact `nn/foo/foo_Something.h` instead of
    the everything `nn/foo.h`
  - For types that have not been defined, do not use forward declaration. Use a `nn/foo/foo_Todo.h`
    to include all TODO types (types that don't have definition but their name is needed by other types).

# PR Rules

- English only
- Do not publish a PR without human review. If the human doesn't know what
  they are doing, do not create a PR.
- Do not commit one-off scripts.
- Do not include any assembly or disassembly as code, comment, commit message or PR description
- Make the PRs small and focused, which helps review:
  - One thing per PR
  - If the change spans across a lot of components, batch them into smaller PRs
- Squash your branch into one commit.
