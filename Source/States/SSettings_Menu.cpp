#include "SSettings_Menu.h"

#include "../Resource_Managers/Resource_Holder.h"

#include "../Application.h"
#include "SPlaying.h"

namespace State
{
    Settings_Menu::Settings_Menu(Application& application, World_Settings& settings)
    :   Game_State          (application)
    ,   m_pWorldSettings    (&settings)
    {
        initMenu();
    }

    void Settings_Menu::input(const sf::Event& e)
    {
        m_pActiveMenu->input(e);
    }

    void Settings_Menu::input(Camera& camera)
    { }

    void Settings_Menu::fixedUpdate(Camera& camera, float dt)
    {
        m_pActiveMenu->update();
    }

    void Settings_Menu::draw(Renderer::Master& renderer)
    {
        m_pActiveMenu->draw(renderer);
    }

    void Settings_Menu::onOpen()
    { }

    void Settings_Menu::initMenu()
    {
        //Front menu
        m_frontMenu.addComponent(std::make_unique<GUI::Button>("Video Settings", [&]()
        {
            m_pActiveMenu = &m_videoSettings;
        }));

        m_frontMenu.addComponent(std::make_unique<GUI::Button>("Back", [&]()
        {
            m_application->popState();
        }));

        //Video settings menu
        m_videoSettings.addComponent(std::make_unique<GUI::Button>("Back", [&]()
        {
            m_pActiveMenu = &m_frontMenu;
        }));
    }
}
