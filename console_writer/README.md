# `write` Function

Prints text to the console character by character, with options to:

- Set a delay between each character (`delayCh`) and after spaces (`delayS`)  
- Apply a color to the text (`color`)

If color is not provided, the text will be printed without color (using the terminal’s default)<br>
If delays are not provided, both default to **40 ms**

All functions are now part of the `consoleTools` namespace.

## Parameters

| Parameter | Type   | Description                                                       |
|-----------|--------|-------------------------------------------------------------------|
| `text`    | string | The text to print                                                 |
| `color`   | int    | ANSI color code to use (if not provided, text will be printed without color) |
| `delayCh` | int    | Delay between characters (milliseconds)                           |
| `delayS`  | int    | Additional delay after spaces (milliseconds)                      |

## ANSI Color Codes

| Color Name     | Code |
|----------------|------|
| Black          | 30   |
| Red            | 31   |
| Green          | 32   |
| Yellow         | 33   |
| Blue           | 34   |
| Magenta        | 35   |
| Cyan           | 36   |
| White          | 37   |
| Bright Black   | 90   |
| Bright Red     | 91   |
| Bright Green   | 92   |
| Bright Yellow  | 93   |
| Bright Blue    | 94   |
| Bright Magenta | 95   |
| Bright Cyan    | 96   |
| Bright White   | 97   |

## Example Usage
```
write(text, color, delayBetweenChars, delayAfterSpace);
```

```cpp
#include "console_writer.h"

int main() {
    consoleTools::write("Hello world!", 32, 50, 100); // Prints green text with delays
    consoleTools::write("No color text.", 0, 50, 100); // Without color
    consoleTools::write("default"); // Default settings
    return 0;
}
```
---
Licensed under MIT License. See the LICENSE file in the root of this repository.
