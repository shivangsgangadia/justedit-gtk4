#ifndef _SRC_JUSTEDIT_INCLUDE_MAIN_HPP
#define _SRC_JUSTEDIT_INCLUDE_MAIN_HPP

#include <gtkmm.h>

/*
 * @brief Initializes the main application UI using JustEdit::Application::initialize
 * Should be called in the GTK applications "activate" signal.
 */
void onAppActivate(Glib::RefPtr<Gtk::Application> app);

/*
 * @brief Entry point
 */
int main(int argc, char *argv[]);

namespace JustEdit {

class Application {
    private:
        // UI related stuff
        std::unique_ptr<Gtk::Window> m_applicationWindow;
        Glib::RefPtr<Gtk::Application> m_application;
        // Other things to be tracked
        bool initialized = false;

        // Singleton
        /*
         * @brief Only accessible constructor. Adds the main window and makes it
         * visible
         */
        Application(Glib::RefPtr<Gtk::Builder> builder, Glib::RefPtr<Gtk::Application> application);
        Application(const Application&) = delete;
        Application(Application&&) noexcept = delete;
        /*
         * @brief Initializes the singleton instance. Must be called before using
         * getInstance. Calls getInstance once, using lambda constructor to force
         * initialization.
         */
        static void initialize(Glib::RefPtr<Gtk::Builder> builder, Glib::RefPtr<Gtk::Application> application);
        friend void ::onAppActivate(Glib::RefPtr<Gtk::Application> app);
    public:

        static Application &getInstance(std::function<Application()> *initObject = nullptr);
};

};


#endif
