#include "IICDiscovery.h"
#include <cstdio>


using namespace Page;

IICDiscovery::IICDiscovery()
{
}

IICDiscovery::~IICDiscovery()
{
}

void IICDiscovery::onCustomAttrConfig()
{
    SetCustomLoadAnimType(PageManager::LOAD_ANIM_OVER_TOP, 600, lv_anim_path_ease_in);



    
}

void IICDiscovery::onViewLoad()
{
    StatusBar::Appear(false);
    Model.Init();
    View.Create(root);

    AttachEvent(root);
}

void IICDiscovery::onViewDidLoad()
{
}

void IICDiscovery::onViewWillAppear()
{
    lv_obj_set_style_opa(root, LV_OPA_TRANSP, 0);
    lv_obj_fade_in(root, 300, 0);
}

void IICDiscovery::onViewDidAppear()
{
    
}

void IICDiscovery::onViewWillDisappear()
{
    lv_obj_fade_out(root, 300, 0);
}

void IICDiscovery::onViewDidDisappear()
{
}

void IICDiscovery::onViewDidUnload()
{
    SetCustomLoadAnimType(PageManager::LOAD_ANIM_OVER_BOTTOM, 600, lv_anim_path_ease_in);
    View.Delete();
    Model.Deinit();
}

void IICDiscovery::AttachEvent(lv_obj_t *obj)
{
    lv_obj_set_user_data(obj, this);
    lv_obj_add_event_cb(obj, onEvent, LV_EVENT_GESTURE, this);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
}

void IICDiscovery::Update()
{

}

void IICDiscovery::onTimer(lv_timer_t *timer)
{

}




void IICDiscovery::onEvent(lv_event_t *event)
{

    lv_obj_t *obj = lv_event_get_target(event);
    lv_event_code_t code = lv_event_get_code(event);
    IICDiscovery *instance = (IICDiscovery *)lv_obj_get_user_data(obj);

    if (obj == instance->root)
    {
        if (LV_EVENT_GESTURE == code)
        {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
            if (LV_DIR_TOP == dir)
            {
                instance->Manager->Pop();
            }
        }
    }
}
