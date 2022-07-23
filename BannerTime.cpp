
#include <MyInclude.h>

/*
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

#include <chrono>
#include <thread>

using namespace std;
*/

#define CLEAR "cls"

/**  Must match the string below  **/
#define GLYPH_WIDTH 8
#define GLYPH_HEIGHT 7

#define GLYPH_SPACING ' '
#define BANNER_SPACE_LEFT 1
#define BANNER_SPACE_TOP  1

string glyphs[] = {
  "         ###  ### ###  # #   ##### ###   #  ##     ###  ",
  "         ###  ### ###  # #  #  #  ## #  #  #  #    ###   ",
  "         ###   #   # ########  #   ### #    ##      #   ",
  "          #            # #   #####    #    ###     #    ",
  "                     #######   #  #  # ####   # #       ",
  "         ###           # #  #  #  # #  # ##    #        ",
  "         ###           # #   ##### #   ### #### #       ",

  "   ##    ##                                            #",
  "  #        #   #   #    #                             # ",
  " #          #   # #     #                            #  ",
  " #          # ### ### #####   ###   #####           #   ",
  " #          #   # #     #     ###           ###    #    ",
  "  #        #   #   #    #      #            ###   #     ",
  "   ##    ##                   #             ###  #      ",

  "  ###     #    #####  ##### #      ####### ##### #######",
  " #   #   ##   #     ##     ##    # #      #     ##    # ",
  "# #   # # #         #      ##    # #      #          #  ",
  "#  #  #   #    #####  ##### ####### ##### ######    #   ",
  "#   # #   #   #            #     #       ##     #  #    ",
  " #   #    #   #      #     #     # #     ##     #  #    ",
  "  ###   ##### ####### #####      #  #####  #####   #    ",

  " #####  #####          ###      #           #     ##### ",
  "#     ##     #         ###     #             #   #     #",
  "#     ##     #   *            #     #####     #        #",
  " #####  ######         ###   #                 #     ## ",
  "#     #      #   *     ###    #     #####     #     #   ",
  "#     ##     #          #      #             #          ",
  " #####  #####          #        #           #       #   ",

  " #####    #   ######  ##### ###### ############## ##### ",
  "#     #  # #  #     ##     ##     ##      #      #     #",
  "# ### # #   # #     ##      #     ##      #      #      ",
  "# # # ##     ####### #      #     ######  #####  #  ####",
  "# #### ########     ##      #     ##      #      #     #",
  "#     ##     ##     ##     ##     ##      #      #     #",
  " ##### #     #######  ##### ###### ########       ##### ",

  "#     #  #*#        ##    # #      #     ##     ########",
  "#     #   #         ##   #  #      ##   ####    ##     #",
  "#     #   #         ##  #   #      # # # ## #   ##     #",
  "#######   #         ####    #      #  #  ##  #  ##     #",
  "#     #   #   #     ##  #   #      #     ##   # ##     #",
  "#     #   #   #     ##   #  #      #     ##    ###     #",
  "#     #  ###   ##### #    # ########     ##     ########",

  "######  ##### ######  ##### ########     ##     ##     #",
  "#     ##     ##     ##     #   #   #     ##     ##  #  #",
  "#     ##     ##     ##         #   #     ##     ##  #  #",
  "###### #     #######  #####    #   #     ##     ##  #  #",
  "#      #   # ##   #        #   #   #     # #   # #  #  #",
  "#      #    # #    # #     #   #   #     #  # #  #  #  #",
  "#       #### ##     # #####    #    #####    #    ## ## ",

  "#     ##     ######## ##### #       #####    #          ",
  " #   #  #   #      #  #      #          #   # #         ",
  "  # #    # #      #   #       #         #  #   #        ",
  "   #      #      #    #        #        #               ",
  "  # #     #     #     #         #       #               ",
  " #   #    #    #      #          #      #               ",
  "#     #   #   ####### #####       # #####        #######",

  "  ###                                                   ",
  "  ###     ##   #####   ####  #####  ###### ######  #### ",
  "   #     #  #  #    # #    # #    # #      #      #    #",
  "    #   #    # #####  #      #    # #####  #####  #     ",
  "        ###### #    # #      #    # #      #      #  ###",
  "        #    # #    # #    # #    # #      #      #    #",
  "        #    # #####   ####  #####  ###### #       #### ",

  "                                                        ",
  " #    #    #        # #    # #      #    # #    #  #### ",
  " #    #    #        # #   #  #      ##  ## ##   # #    #",
  " ######    #        # ####   #      # ## # # #  # #    #",
  " #    #    #        # #  #   #      #    # #  # # #    #",
  " #    #    #   #    # #   #  #      #    # #   ## #    #",
  " #    #    #    ####  #    # ###### #    # #    #  #### ",

  "                                                        ",
  " #####   ####  #####   ####   ##### #    # #    # #    #",
  " #    # #    # #    # #         #   #    # #    # #    #",
  " #    # #    # #    #  ####     #   #    # #    # #    #",
  " #####  #  # # #####       #    #   #    # #    # # ## #",
  " #      #   #  #   #  #    #    #   #    #  #  #  ##  ##",
  " #       ### # #    #  ####     #    ####    ##   #    #",

  "                       ###     #     ###   ##    # # # #",
  " #    #  #   # ###### #        #        # #  #  # # # # ",
  "  #  #    # #      #  #        #        #     ## # # # #",
  "   ##      #      #  ##                 ##        # # # ",
  "   ##      #     #    #        #        #        # # # #",
  "  #  #     #    #     #        #        #         # # # ",
  " #    #    #   ######  ###     #     ###         # # # #"};




void printBanner(char bannertime[12]) {
  // int a, b, c, len, ind, i;

  int a;      /* Working line of glyph  */
  int b;      /* Working char of banner */
  int c;      /* Working row of glyph   */
  int len;    /* Length of banner       */
  int ind;
  //int i;


  char line[80];

  // int glyphW=GLYPH_WIDTH;
  // int glyphH=GLYPH_HEIGHT;
  // int bannerSpL=BANNER_SPACE_LEFT;
  // int bannerSpT=BANNER_SPACE_TOP;

  int lenBanner = strlen (bannertime);
  //lenBanner = lenBanner+2; // Add padding //;
  
  /*  Run once, for now  */
  for (int i=0; i<1; i++ ) {
    if (lenBanner > 12) {
      lenBanner = 12;
    }

   /* Padding on the left */
   /* This will lead to full glyph width */
   //string strPadding = "\t";
  //  string strPadding = "";
  //  string tmpbanner = "";
  //  tmpbanner=strPadding.c_str();
  //  tmpbanner+=bannertime;
  //  strcpy (bannertime, tmpbanner.c_str());

    /*  Padding lines on top  */
    system(CLEAR);
    // for (int j=0; j <= BANNER_SPACE_TOP; j++) {
    int j=0;
    while (j < BANNER_SPACE_TOP) {
        cout << "\n";
        j++;
    }

    /*  Create  and print row by row  */
    for (a = 0; a < GLYPH_HEIGHT; a++) {
      for (b = 0; b < lenBanner; b++) {
        if ((ind = bannertime[b] - ' ') < 0) {
          ind = 0;
        }

	      for (c = 0; c < GLYPH_HEIGHT; c++) {
	        line[b * GLYPH_WIDTH + c] = glyphs[(ind / GLYPH_WIDTH * GLYPH_HEIGHT) + a][(ind % GLYPH_WIDTH * GLYPH_HEIGHT) + c];
	      }
	      line[b * GLYPH_WIDTH + GLYPH_HEIGHT] = GLYPH_SPACING;
      }

      for (b = lenBanner * GLYPH_WIDTH - 1; b >= 0; b--) {
	      if (line[b] != ' ') {
	        break;
        }
	      line[b] = '\0';
      }

      /*  Spacer left of banner  */
      // for (int k=0; k <= BANNER_SPACE_LEFT; k++) {
      int k=0;
      while (k < BANNER_SPACE_LEFT) {
        cout << "  ";
        k++;
      }

      //puts(line);
      cout << line;

      if (a <= GLYPH_HEIGHT) {
        cout << "\n";
      }

    }
    //puts("");
    //cout << line << "\n";

  }

  return;
}



int main(void) {
// int main (int argc, char* argv[]) {
    // int res = sanitazeInput (argc, argv);
    // if (res != true) {
    //   cout << "____Oups,_found_something_in_the_input____" << nl;
    // }

    int sec_prev=0;
    int seconds, minutes, hours;
    for (int i=0; i<10000000000;  i++) {
    // while (false) {
        /*  Storing total epoc seconds  */
        time_t total_seconds=time(0);

        /*  Get values of seconds, minutes and hours  */
        struct tm* ct=localtime(&total_seconds);
  
        seconds=ct->tm_sec;
        minutes=ct->tm_min;
        hours=ct->tm_hour;
    
        /*  Print result  */
        if ((seconds >= sec_prev+1) || (sec_prev==59 && seconds==0)) {

            string strTimeNow="";

            /*  Add 0-prefix to single digit number  */
            stringstream QQtimeNow;
            QQtimeNow << (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"") << minutes << ":" << (seconds<10?"0":"") << seconds;
            QQtimeNow >> strTimeNow;

            char timeNow[10];
            strcpy (timeNow, strTimeNow.c_str());
            printBanner(timeNow);
    
        } else {
          /*  Sleep for a while  */
          std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

    sec_prev=seconds;
    
    }

  cout << "End of time - Get ready ..." << "\n" << endl;
  return 0;
}
