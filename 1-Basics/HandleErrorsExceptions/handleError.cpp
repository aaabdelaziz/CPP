#include <iostream>
using namespace std;

class Printer{
        float available_num_papers;
        std::string printer_name;
    public:
        Printer(std::string printer_name, int available_num_papers): 
        printer_name(printer_name), available_num_papers(available_num_papers) {
            cout << "printer instant created with" <<
             "paper name: \"" << printer_name <<
             "\" has num of papers " << available_num_papers << endl;
        }

        void PrintLetter(std::string letter){

            // throw exception if the number of required papers exceed the 
            // calculate the number of requiered papers to print the letter,
            // assuming that the one paper can carry up to 10 letters
            cout << "letter has " << letter.length() << " characters" << endl;
            float num_of_required_papers = letter.length() / 10.0;
            cout << "num_of_required_papers" << num_of_required_papers << endl;
            // check if there is enough papers available in printer before printing
            if ((int)num_of_required_papers > available_num_papers){
                throw 102;   // throw exception of int type    (only this exception will be executed)
                //throw an exception
                throw "No enough papers in Printer";   // throw exception of string type 

                
            }
            
            //else print the letter
            cout << "Printing letter.... "  << endl << letter <<  endl;

        }

};


int main() {

    // create a printer with only 5 papers
    Printer p("HP H12 Printer",5);
    
    try{
        p.PrintLetter("hello my friend how are you doing, I wish every thing is good with you\n");
        // p.PrintLetter("hello my friend how are you doing, I wish every thing is good with you\n");
        // p.PrintLetter("hello my friend how are you doing, I wish every thing is good with you\n");
    }
    catch (const char* textException){
        cout << "Exception...String  " << textException << endl;
    }
    catch (int  exCode){
        cout << "Exception...Code   " << exCode << endl; // (only this exception will be executed) as it's the first throw message
    }
    catch (...){  // if the other above catches doesn't receive string or int exception type, the default catch here will be executed
        cout << "execute default " << endl;
    }

  
  return 0;
}
