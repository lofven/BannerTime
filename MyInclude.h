/**  Bunch of libs we use frquently  **/
#include <stdio.h>              /*  Usual suspects          */
#include <iostream>

#include <math.h>
#include <time.h>               /*  Read clock              */

#include <vector>
#include <string>
#include <cstring>              /*  Allow strcpy etc        */
#include <sstream>              /*  Stream to string        */
#include <fstream>              /*  File-handling           */

#include <chrono>               /*  Sleep for <time>        */
#include <thread>               /*  Multithread, sleep_for   */
#include <typeinfo>             /*  Dubugging, typeid       */


/**  Mostly we work here  **/
using namespace std;


/**  Shortcuts  **/
#define ULL unsigned long long
#define noop                                                        /*  No-op "function"                                    */
#define NL "\n"                                                     /*  Stringify output                                    */
const string    nl              = "\n";                             /*  Stringify output                                    */


/**  When looking for end of string  **/
auto nposv              = std::string::npos;


/*  Check for these in argv, used in sanitazeInput      */
vector<string>  vectBadChars    = {"\\", "\/", ":", "..", "num"};



bool sanitazeInput (int largc=0, char *largv[]={}) {
    /*  Called first from main()  */
    /*  Sanitaze input arguments  */

    /*  Assume everything is fine, until its not  */
    bool status             = true;

    cout << "Running sanitaze" << nl;
    if (true) {
        cout << "ArgC: " << largc << nl;
        for (int c=0; c < largc; c++) {
            cout << "ArgV [ " << c << " ]: " << largv[c] << nl;

            /*  Stringify so we can use .find   */
            string argvs = largv[c];

            for (auto bc = vectBadChars.begin(); bc < vectBadChars.end(); bc++) {
                cout << "Looking for bad chars:  " << *bc;
                if (argvs.find(*bc) != nposv) {
                    cout << " - Found" << nl;
                    status = false;
                } else {
                    cout << " - Not found";
                    cout << nl;
                }
            }


        }
    }
    cout << "Sanitaze done" << nl;

    return status;
}   /**  bool = sanitazeInput (argc, argv)                   **/
