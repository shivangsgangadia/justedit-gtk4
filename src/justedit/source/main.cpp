#include <gtkmm.h>

#ifndef MAIN_APPLICATION_XML
#error "Application XML not found"
#endif

#include "main.hpp"

JustEdit::Application::Application(Glib::RefPtr<Gtk::Builder> builder, Glib::RefPtr<Gtk::Application> app) {
    m_application = app;
    // Retreive object from the XML..
    m_applicationWindow = std::unique_ptr<Gtk::Window>(builder->get_widget<Gtk::Window>("application_window"));
    // .. And add it to the already initialized application
    m_application->add_window(*m_applicationWindow);
    m_applicationWindow->set_visible(true);
}

auto JustEdit::Application::getInstance(std::function<JustEdit::Application()> *init) -> JustEdit::Application& {
    // Initialize this static instance with a memory block created from any constructor
    // of my class Application
    // Brace initialization does not call a constructor - it's basically memcpy
    static JustEdit::Application instance{(*init)()};
    return instance;
}

void JustEdit::Application::initialize(Glib::RefPtr<Gtk::Builder> builder, Glib::RefPtr<Gtk::Application> application) {
    // This function returns a memory block of Application, created using one of
    // it's constructors
    std::function<JustEdit::Application()> initializer = [builder, application]() {
        return JustEdit::Application(builder, application);
    };
    // Force object creation
    (void) JustEdit::Application::getInstance(&initializer);
}

void onAppActivate(Glib::RefPtr<Gtk::Application> app) {
    auto builder = Gtk::Builder::create_from_file(MAIN_APPLICATION_XML);
    JustEdit::Application::initialize(builder, app);
    // Now onwards, it's safe to use the singleton instance of Application
}

int main(int argc, char *argv[]) {
    auto application = Gtk::Application::create();

    // Indirect initialization because adding widgets requires the application to already be registered and running
    application->signal_activate().connect([application](){
        onAppActivate(application);
    });

    return application->run(argc, argv);
}
