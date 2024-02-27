#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md

    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */
    if(m_Giraffe->IfCollides(m_Chest)){
        m_Chest->SetVisible(false);
    }

    for(int i=0;i<3;i++){
        if(m_Giraffe->IfCollides(m_Doors[i]) && m_Doors[i]->GetVisibility()){
            m_Doors[i]->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
        }
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::W)) {
        auto NewPos = m_Giraffe->GetPosition();
        NewPos.y += 5;
        m_Giraffe->SetPosition(NewPos);

    }
    if (Util::Input::IsKeyPressed(Util::Keycode::S)) {
        auto NewPos = m_Giraffe->GetPosition();
        NewPos.y -= 5;
        m_Giraffe->SetPosition(NewPos);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        auto NewPos = m_Giraffe->GetPosition();
        NewPos.x -= 5;
        m_Giraffe->SetPosition(NewPos);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::D)) {
        auto NewPos = m_Giraffe->GetPosition();
        NewPos.x += 5;
        m_Giraffe->SetPosition(NewPos);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::R)) {
        m_Ball->SetPlaying(true);
    }
    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)) {
        auto cursorPos = Util::Input::GetCursorPosition();
        LOG_DEBUG("Mouse clicking! x:{}, y{}", cursorPos.x, cursorPos.y);
    }

    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
