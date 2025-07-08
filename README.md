# 🚀 NWeb – Native Web Renderer

[![MIT License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

NWeb is a blazing fast, lightweight native web renderer inspired by Electron, but designed to consume less memory and deliver superior speed! ⚡️

---

## ✨ Features

- 🪶 **Lightweight**: Minimal memory usage, no unnecessary bloat.
- ⚡ **Fast**: Rapid startup and snappy performance.
- 🛠️ **Native**: Built using C++ and [webview/webview](https://github.com/webview/webview) for true native integration.
- 💻 **Simple Build**: Uses CMake for easy cross-platform compilation.
- 🔒 **Open Source**: MIT licensed for maximum freedom.

---

## 📦 Directory Structure

```
.
├── src/           # Source code (main.cpp, etc)
├── Release/       # Compiled binaries and dependencies
├── config.txt     # Application configuration
├── CMakeLists.txt # Build script
├── LICENSE        # MIT License
└── README.md      # This file
```

---

## 🖥️ Getting Started

### Prerequisites

- 🛠️ CMake >= 3.16
- 🖥️ C++ Compiler (e.g. MSVC, GCC, Clang)
- 🕸️ [webview/webview](https://github.com/webview/webview) (auto-fetched by CMake)

### 🔧 Build Instructions

```bash
git clone https://github.com/Fyonietz/Native-Web.git
cd Native-Web
cmake -S . -B build
cmake --build build
```

The executable will be generated as `NWeb.exe` in the project root.

---

## ⚙️ Configuration

Edit `config.txt` to customize:

```ini
name=Elevate
server=http://localhost:9090/
fullscreen=1
```

---

## 🏃‍♂️ Running

Double-click `NWeb.exe` or run from terminal:

```bash
./NWeb.exe
```

---

## 🤝 Contributing

PRs, issues and suggestions are welcome! Please open an issue for bugs or feature requests.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE) © 2025 Habib Herdiansyah

---

## 🙏 Credits

- [webview/webview](https://github.com/webview/webview) – the tiny webview library powering NWeb

---

> Made with ❤️ by [Habib Herdiansyah](https://github.com/Fyonietz)
