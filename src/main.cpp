#define WEBVIEW_IMPLEMENTATION
#include "webview.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <commctrl.h>

std::unordered_map<std::string,std::string> loadConfig(const std::string &filename){
    std::unordered_map<std::string,std::string> config;
    std::ifstream file(filename);

    if(!file){
        std::cerr << "Failed to Open Config File:" << filename << std::endl;
        return config;
    }

    std::string line;
    while(std::getline(file,line)){
        if(line.empty() || line[0] == '#') continue;

        std::istringstream iss(line);
        std::string key, value;
        if(std::getline(iss,key,'=') && std::getline(iss,value)){
            config[key] = value;
        }
    }
    return config;
};

void fullscreen(HWND &hwnd){
     // Remove borders and title bar
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style &= ~(WS_OVERLAPPEDWINDOW); // remove title bar, borders, etc.
    style |= WS_POPUP;               // full borderless window
    SetWindowLong(hwnd, GWL_STYLE, style);

    // Resize and move to cover the screen
    SetWindowPos(hwnd, HWND_TOP, 0, 0,
        GetSystemMetrics(SM_CXSCREEN),
        GetSystemMetrics(SM_CYSCREEN),
        SWP_FRAMECHANGED | SWP_SHOWWINDOW);
}

int main() {
    auto config = loadConfig("config.txt");
    std::string server = config["server"];
    std::string name = config["name"];
    webview_t w = webview_create(1, nullptr);
    webview_set_title(w, name.c_str());
    webview_set_size(w, 1024, 768, WEBVIEW_HINT_NONE);
    webview_navigate(w, server.c_str());
   // ⚠️ Sleep a little to ensure the window is created
    Sleep(100);

    // Get the native window handle
    HWND hwnd = (HWND)webview_get_window(w);

    if(config.count("fullscreen")){
        std::string value = config["fullscreen"];
        if(value == "1" || value == "true" || value== "yes"){
            fullscreen(hwnd);
        }
    }
   


    // Run WebView
    webview_run(w);
    webview_destroy(w);
    return 0;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    return main();
}
