#include <iostream>

#include <QIcon>

#include "dispval.h"
#include "../../controlpanel/plugin.h"

/*int main ( int argc, char **argv )
{
	QApplication app ( argc, argv );
	app.setOverrideCursor( QCursor( Qt::BlankCursor ) );
	
	Display dlg;
	dlg.showFullScreen();
	dlg.show();
	
	return app.exec();
}*/

namespace Msg
{
    class DispValuesPlugin : public Plugin
    {
     public:
            DispValuesPlugin()
            {
                    std::cout << "DispValuesPlugin created" << std::endl;
                    dlg = NULL;
            }

            virtual ~DispValuesPlugin()
            {
                    std::cout << "DispValuesPlugin destroyed" << std::endl;
                    delete dlg;
            }

            virtual std::string init()
            {
                    //std::cout << "I am a Fun PlugIn" << std::endl;
                return "Fluksometer";
            }

            virtual QWidget* getWidget()
            {
                if ( dlg == NULL )
                {
                    qDebug() << "Creating new Display";
                    dlg = new Msg::Display();
                    connect ( dlg, SIGNAL( closeDisplay() ), this, SIGNAL( stopWidget() ) );
                }
                return dlg;
            }

            virtual QIcon* getIcon() {
                return new QIcon(":/dispval/resources/msg.png");
            }
    private:
            Msg::Display* dlg;
    };

    //
    // The PlugInFunFactory class inherits from PlugInFactory
    // and creates a PlugInFun object when requested.
    //


    class DispValuesPluginFactory : public PluginFactory
    {
     public:
            DispValuesPluginFactory()
            {
            }

            ~DispValuesPluginFactory()
            {
            }

            virtual Plugin * CreatePlugin()
            {
                    return new DispValuesPlugin;
            }

    };


    //
    // The "C" linkage factory0() function creates the PlugInFunFactory
    // class for this library
    //


}

extern "C" void * factory0( void )
{
				return new Msg::DispValuesPluginFactory;
}
