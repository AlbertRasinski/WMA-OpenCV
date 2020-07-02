#include "MyForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

[STAThreadAttribute]
void Main(array<System::String^>^ args){
	Application::SetCompatibleTextRenderingDefault(false);
	WidzenieMaszynoweProjekt::MyForm Form;
	Application::Run(% Form);
}