# resolve-codec-fixer
A shitty Linux DaVinci Resolve codec fixer I made in 5 minutes.

This tool will fix missing audio in imported clips.

To use it, modify the `extension` and `path` strings. This program is very dangerous, so ensure you specify the correct path.

To run it:

```sh
g++ fixer.cpp && ./a.out
```

Why did I make this in C++? I don't know or care.