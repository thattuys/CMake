#include "Leadwerks.h"
#include "ComponentSystem.h"
#include "Encryption.h"
//#include "Steamworks/Steamworks.h"

using namespace Leadwerks;

int main(int argc, const char* argv[])
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
    
    //Get the displays
    auto displays = GetDisplays();

    //Create a window
    auto window = CreateWindow("Leadwerks", 0, 0, 1280 * displays[0]->scale, 720 * displays[0]->scale, displays[0], WINDOW_CENTER | WINDOW_TITLEBAR);

    //Create a framebuffer
    auto framebuffer = CreateFramebuffer(window);

    //Create a world
    auto world = CreateWorld();
    
    //Load packages
    std::vector<std::shared_ptr<Package> > packages;
    auto dir = LoadDir("");
    String password;
    GetPassword(password);
    for (auto file : dir)
    {
        if (ExtractExt(file).Lower() == "zip")
        {
            auto pak = LoadPackage(file);
            if (pak)
            {
                if (not password.empty())
                {
                    pak->SetPassword(password);
                    pak->Restrict();
                }
                packages.push_back(pak);
            }
        }
    }
    //password.Clear();

    //Load the map
    WString mapname = "Maps/start.ultra";
    if (cl["map"].is_string()) mapname = std::string(cl["map"]);
    auto scene = LoadScene(world, mapname);

    //Main loop
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