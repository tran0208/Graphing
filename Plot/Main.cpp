#include "Main.h"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{



	// The important lines:
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);
    //printf("Hello World!");

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Plot::Main Form1;
	Application::Run(%Form1);



	return 0;

}



    System::Void Plot::Main::button1_Click(System::Object^  sender, System::EventArgs^  e)
    { 
		try 
        { 
			//show the open file dialog to user
			//this->FileDialogA->Title = "Input Data";
			//this->FileDialogA->FileName = ""; 
			DialogResult = this->FileDialogA->ShowDialog();
            if (DialogResult == Windows::Forms::DialogResult::OK)
            {

            }
            else
            {

            }  
        }
        catch( Exception ^ex)
        {
           
        } 
    }



   System::Void Plot::Main::button2_Click(System::Object^  sender, System::EventArgs^  e)
   {
	   //double value = ((rand() % 99) + 1) / 100.0;  
	   try
	   {
           this->inputValue = Convert::ToDouble(textBox1->Text);  

		   cout << this->inputValue << " \n";
		   this->RollingPointPairListObj->Add(this->t , this->inputValue , this->t);
		   //this->zedGraphObj->AxisChange();
 

           //Save largest and smallest value in the y axis
           if (this->trackYMAX < this->inputValue)
           {
			   this->trackYMAX = this->inputValue;
			   this->yscale->Max = this->trackYMAX + minorYStep;
           } 
		   if (this->trackYMIN > this->inputValue)
		   {
			   this->trackYMIN = this->inputValue;
			   this->yscale->Min = this->trackYMIN - minorYStep;
		   }

 

           if (t > XLENGTH) 
           { 
			   this->xscale->Max = t ;
			   this->xscale->Min = t - XLENGTH + MINORXSTEP;
           } 
          
		   label1->Text = "x = " + Convert::ToString(t);
		   this->t++;

		   this->zedGraphObj->Refresh();

		  // this->xScale->Max = this->currentX;
		  // this->xScale->Min = this->xScale->Max - XLENGTH * this->ts;

		   //vector<double> v = { 5, 2, 8, 10, 9 };
		   //int maxElementIndex = std::max_element(v.begin(), v.end()) - v.begin();
		  //int maxElement = *std::max_element(v.begin(), v.end());



       }
	   catch (FormatException^ ex)
       {
		   textBox1->Text = "";
	   }  
   }



    System::Void Plot::Main::button3_Click(System::Object^  sender, System::EventArgs^  e) 
    {
		Close();
	}



