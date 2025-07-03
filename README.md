# NWeb (Native-Web)

_NWeb is a native web renderer similar to Electron, but is designed to be fast and consume less memory._

## Overview

NWeb lets you build lightweight desktop applications using web technologies, powered by a native C++ backend and the [webview](https://github.com/webview/webview) library. Unlike Electron, NWeb is minimal, efficient, and provides seamless fullscreen and windowed experiences.

## Features

- ⚡️ Efficient, lightweight C++ codebase (no Node.js runtime required)
- 🚀 Fast startup and low memory usage
- 🖥️ Renders web content in a native window (via [webview](https://github.com/webview/webview))
- 🖱️ Simple configuration via `config.txt` (set server URL, window name, fullscreen mode, etc.)
- 🛠️ Easy build with CMake and Visual Studio (Windows)

## Getting Started

### Prerequisites

- Windows OS
- [Visual Studio 2022](https://visualstudio.microsoft.com/vs/) (with Desktop development with C++ workload)
- [CMake](https://cmake.org/) >= 3.16

### Clone the Repository

```bash
git clone https://github.com/Fyonietz/Native-Web.git
cd Native-Web
```

### Configure Your App

Edit `config.txt` to set the application window name, web server URL, and fullscreen mode:

```
name=Elevate
server=http://localhost:9090/
fullscreen=1
```

### Build & Run

Use the build script (Windows):

```batch
cd scripts
build.cmd
```

Or build manually:

1. Open a "Developer Command Prompt for VS 2022".
2. Run:
   ```bash
   cmake -S . -B build -G "Visual Studio 17 2022"
   cmake --build build --config Release
   ```
3. Run the executable (`NWeb.exe`) generated in the repo root.

## How It Works

- `src/main.cpp` loads your configuration from `config.txt`, initializes a webview window, and navigates to your chosen server URL.
- If `fullscreen=1` is set, the app launches in fullscreen mode.
- All rendering is handled natively for performance and low resource usage.

## File Structure

- `src/main.cpp` &mdash; Main application source code
- `config.txt` &mdash; Configuration file (server URL, name, fullscreen)
- `CMakeLists.txt` &mdash; Build configuration
- `scripts/build.cmd` &mdash; Windows build and run script

## Contributing

Pull requests and suggestions are welcome! Please file issues or PRs on the [GitHub repo](https://github.com/Fyonietz/Native-Web).

## License

MIT License (see [LICENSE](LICENSE))

---

> _NWeb: Native web rendering, minimal overhead._
