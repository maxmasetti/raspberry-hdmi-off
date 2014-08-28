## Rasperry Pi screenblankerd

Screenblankerd is a background program that turn off/on the hdmi or tv of your Raspberry Pi due to inactivity or key pressing on the connected keyboard.

In order to use srcreenblankerd download and compile the file:
<pre>
# make
</pre>

than run screenblankerd as superuser and send it to background:
<pre>
# sudo ./screenblankerd &
</pre>

This is only a first beta release, I'm using it with my RPi with no problem, but feel free to contact me for any issue or request.

## Requirements

In order to run, the program requires tvservice and fbset installed.

## License

The MIT License (MIT)

Copyleft (ɔ) 2014 Max Masetti

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
