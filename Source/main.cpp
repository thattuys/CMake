#include "UltraEngine.h"
#include "ComponentSystem.h"

#ifdef USE_STEAMWORKS
#include "Steamworks/Steamworks.h"
#endif

using namespace UltraEngine;

int main(int argc, const char *argv[])
{

#ifdef STEAM_API_H
    if (not Steamworks::Initialize())
    {
        RuntimeError("Steamworks failed to initialize.");
        return 1;
    }
#endif

    RegisterComponents();

    auto cl = ParseCommandLine(argc, argv);

    // Load FreeImage plugin (optional)
    auto fiplugin = LoadPlugin("Plugins/FITextureLoader");

    // Get the displays
    auto displays = GetDisplays();

    // Create a window
    auto window = CreateWindow("Ultra Engine", 0, 0, 1280 * displays[0]->scale, 720 * displays[0]->scale, displays[0], WINDOW_CENTER | WINDOW_TITLEBAR);

    // Create a framebuffer
    auto framebuffer = CreateFramebuffer(window);

    // Create a world
    auto world = CreateWorld();

    // Load the map
    WString mapname = "Maps/start.ultra";
    if (cl["map"].is_string())
        mapname = std::string(cl["map"]);
    auto scene = LoadMap(world, mapname);

    // Main loop
    while (window->Closed() == false and window->KeyDown(KEY_ESCAPE) == false)
    {
        world->Update();
        world->Render(framebuffer);

#ifdef STEAM_API_H
        Steamworks::Update();
#endif
    }

#ifdef STEAM_API_H
    Steamworks::Shutdown();
#endif

    return 0;
}
