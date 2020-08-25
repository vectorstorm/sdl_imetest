This is the simplest possible test program for testing SDL2's IME text
entry functionality.

To test, set your keyboard to an IME-using setting (I tend to test with
japanese or traditional chinese), focus the keyboard on the window that
the program opens, and begin to type.  In theory, the IME candidate list
should open and let you select composed glyphs.

The program provides output to the console, showing you both the current
candidate text and the current actual composed glyphs.  (This assumes
that your console is able to display UTF-8-encoded text)  But the main
purpose of this test program is just to prove that SDL2 can trigger the
IME's candidate list to appear across all platforms.

For convenience on Windows, the CMake project has an 'install' target
which will copy the built executable and the SDL2.dll file into an
'install' directory from which it can be run, and a 'package' target
which will zip them together into a distributable file.
