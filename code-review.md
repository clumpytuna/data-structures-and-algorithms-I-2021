# Code-review

## Code-style

To write the code, use [Google C++ Style Guide].

## Code-review passing algorithm

 1. Pass tests in the contest.
 2. Fill [code-review form]. Remarks will be sent to the email address specified in the form. If there is a single problem in contest for code review you can send only this problem in the form, if there is a random problem you need to send **all!** problems to the form one by one.
 3. Fix the remarks and **send the fixed solution again to the contest**. If the solution is not sent to the contest, it will not be checked.
 4. Send the **link to the successfully passed solution** in a reply email.

**N.B.** As you progress through the code-review, new remarks may appear (if the code has a significant number of flaws, then the reviewer may limit himself to an incomplete list of comments). The number of iterations and the time during which you can correct the solution is limited. On average, one iteration will take about 5 days. 

## Assessment

The final score is based on the last fixed solution. The score depends on the number of remaining errors, as well as the nature of the errors themselves. For example, incorrect memory management (double free, memory leak) or the use of C-style arrays leads to a more significant reduction in the evaluation than poor logical organization of the code or poor naming of variables.

## Tips for passing code-review & contest verification
### Using linters

Before sending code, we recommend checking the code using [clang-format] and [clang-tidy]. See [here](clion-set-up.md) how to set up linters properly.

[//]: #
[Google C++ Style Guide]: <https://google.github.io/styleguide/cppguide.html>
[adress sanitazer]: https://github.com/google/sanitizers/wiki/AddressSanitizer
[CLion]: https://www.jetbrains.com/clion
[CLion clang-tidy]: https://www.jetbrains.com/help/clion/clang-tidy-checks-support.html
[CLion clang-format]: https://www.jetbrains.com/help/clion/clangformat-as-alternative-formatter.html
[code-review form]: https://docs.google.com/forms/d/e/1FAIpQLSe7e_sq0AIppkzpWojK08FzfrEoW3gL8inj3Z7oNt9jqXRv1Q/viewform
[results table]: https://docs.google.com/spreadsheets/d/1y64zLuW_gzcHhovapxaTmpZBLJJldIJtJb5paGbvseM/edit#gid=0
[clang-format]: https://clang.llvm.org/docs/ClangFormat.html
[clang-tidy]: https://clang.llvm.org/extra/clang-tidy/
[.clang-format]: https://github.com/clumpytuna/data-structures-and-algorithms-I-2021/blob/main/.clang-format
[.clang-tidy]: https://github.com/clumpytuna/data-structures-and-algorithms-I-2021/blob/main/.clang-tidy


