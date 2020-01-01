#include QMK_KEYBOARD_H

//This is a keymap for a 12 key macro pad called the ROMAC by Kingly_Keys // This keymap was created by /u/iamwzy to make a digestable macro keymap for users new to this system!
//If this is your first time with macros and configuring a keyboard through a file (not online) I recommend Chokkan's youtube tutorial to set up a build environment as well as writing your own keymap: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> www.youtube.com/playlist?list=PLYEUsdlqPD2a3kzQgnF98Prj-4IzZJGYG
//This keymap is made to be as user friendly as possible, I recommend using Sublime Text or other 3rd party text editors that will help separate different segments of code for easier recognition of errors and is easy to digest: >>>	www.sublimetext.com
//If any questions come up, I recommend the OLKB subreddit, its the more technical keyboard sub with plenty of people well equipped to help you out! >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> www.reddit.com/r/olkb

//MACRO NAMES (MAKE SURE THESE ARE NOT EXISTING CODES IN QMK ALREADY)

enum {MAC_BK = SAFE_RANGE, /*1*/ /*(First Macro Name uses "SAFE_RANGE" after it for compatibility)*/
	/*2*/MAC_P1,
	/*3*/MAC_P2,
	/*4*/MAC_P3,
	/*5*/MAC_P4,
	/*6*/MAC_P5,
	/*7*/MAC_P6,
	/*8*/MAC_DP,
	/*9*/MAC_YT,
	/*10*/MAC_RD,
	/*11*/MAC_D2L,
	/*12*/MAC_CW,
	/*13*/MAC_NEW,
	/*14*/MAC_OPN,
};

//MACRO CODES (THIS IN COMBO WITH MACRO NAMES CAN BE PLACED IN YOUR KEYMAP FOR ANY KEYBOARD, NOT JUST THE ROMAC)
	//See notes for each "SEND_STRING" line to see what each macro does

bool process_record_user(uint16_t keycode, keyrecord_t *record) { 	  /*|					            |*/
	if(record->event.pressed) {										  /*| No Need To Change These Lines |*/
		switch(keycode) {											  /*|					            |*/
			case MAC_BK:
				SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_LEFT)SS_UP(X_LSHIFT)SS_UP(X_LCTRL)SS_TAP(X_DELETE));		//THIS DELETES THE LAST WORD TYPED
				return false; break;
			case MAC_P1:
				SEND_STRING("password1");	//THIS IS PASSWORD 1 (I RECOMMEND USING 16-22 DIGITS DEPENDING ON WEBSITE)
				return false; break;
			case MAC_P2:
				SEND_STRING("password2");	//THIS IS PASSWORD 2
				return false; break;
			case MAC_P3:
				SEND_STRING("password3");	//THIS IS PASSWORD 3
				return false; break;
			case MAC_P4:
				SEND_STRING("password4");	//THIS IS PASSWORD 4
				return false; break;
			case MAC_P5:
				SEND_STRING("password5");	//THIS IS PASSWORD 5
				return false; break;
			case MAC_P6:
				SEND_STRING("password6");	//THIS IS PASSWORD 6
				return false; break;
			case MAC_DP:
				SEND_STRING("123456");		//THIS CAN BE USED FOR A SIMPLE PASSWORD USED FOR DESKTOP OR RANDOM SITES
				return false; break;
			case MAC_YT:
				SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_T)SS_UP(X_LCTRL) "youtube.com" SS_TAP(X_ENTER));				//THIS GOES TO YOUTUBE IN A NEW TAB 
				return false; break;
			case MAC_RD:
				SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_T)SS_UP(X_LCTRL) "reddit.com" SS_TAP(X_ENTER));				//THIS GOES TO REDDIT IN A NEW TAB (All of the website codes can have errors if you have auto fill enabled, reddit is particularly bad about this).
				return false; break;
			case MAC_D2L:
				SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_T)SS_UP(X_LCTRL) "google.com" SS_TAP(X_ENTER));				//THIS GOES TO GOOGLE IN A NEW TAB
				return false; break;
			case MAC_CW:
				SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_W)SS_UP(X_LCTRL));												//THIS CLOSES THE CURRENT WINDOW (BROWSER)
				return false; break;
			case MAC_NEW:
				SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_C)SS_TAP(X_T)SS_TAP(X_V)SS_UP(X_LCTRL)SS_TAP(X_ENTER));		//COPIES HIGHLIGHTED TEXT AND PASTES IT IN A NEW TAB (FAST WAY TO SEARCH VOCAB AND WEBSITE SOURCES [PRACTICAL FOR STUDENTS] )
				return false; break;	
			case MAC_OPN:
				SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_T)SS_UP(X_LCTRL));												//OPENS A BLANK NEW TAB (BROWSER)
				return false; break;								
			}			/*|					              |*/
		}				/*| No Need To Change These Lines |*/
	return true;		/*|					              |*/
};						/*|					              |*/

//KEYMAP (THIS IS WHERE )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/*LEGEND: 	 ^      = KC_TRANS (Prevents layer lock, use in same position in layer above normal function keys)
			    fn#     = *hold* to enable # layer temporarily (normal function)
			    to#     = *tap* enables # layer "permanently" (until new layer is activated)
			    MAC#    = see "macro names" section to find corresponding number/name
			  (blank)   = KC_NO or disabled
	*/


	/*LAYER 0 	[  7  ] [  8  ] [  9  ]
				[  4  ] [  5  ] [  6  ]
				[  1  ] [  2  ] [  3  ]
				[  .  ] [  0  ] [ fn1 ]	*/

	[0] = LAYOUT(KC_P7, KC_P8, KC_P9, \
				KC_P4, KC_P5, KC_P6, \
				KC_P1, KC_P2, KC_P3, \
				KC_PDOT, KC_P0, MO(1)),

	/*LAYER 1 	[  -  ] [  *  ] [  +  ]
				[     ] [  /  ] [     ]
				[ esc ] [     ] [     ]
				[ ent ] [ fn2 ] [  ^  ]	*/

	[1] = LAYOUT(KC_PMNS, KC_PAST, KC_PPLS, \
				KC_NO, KC_PSLS, KC_NO, \
				KC_ESC, KC_NO, KC_NO, \
				KC_PENT, MO(2), KC_TRNS),

	/*LAYER 2 	[     ] [     ] [     ]
				[     ] [     ] [     ]
				[     ] [     ] [     ]
				[ to3 ] [  ^  ] [     ]	*/

	[2] = LAYOUT(KC_NO, KC_NO, KC_NO, \
				KC_NO, KC_NO, KC_NO, \
				KC_NO, KC_NO, KC_NO, \
				TO(3), KC_TRNS, KC_NO),

	/*LAYER 3 	[  Q  ] [  W  ] [MAC1 ]
				[MAC9 ] [MAC10] [MAC11]
				[MAC12] [MAC14] [MAC13]
				[  ^  ] [ fn4 ] [ to0 ]	*/

	[3] = LAYOUT(KC_Q, KC_W, MAC_BK, \
				MAC_YT, MAC_RD, MAC_D2L, \
				MAC_CW, MAC_OPN, MAC_NEW, \
				KC_TRNS, MO(4), TO(0)),

	/*LAYER 4 	[     ] [     ] [     ]
				[     ] [     ] [     ]
				[     ] [     ] [     ]
				[     ] [  ^  ] [ fn5 ]	*/

	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, \
				KC_NO, KC_NO, KC_NO, \
				KC_NO, KC_NO, KC_NO, \
				KC_NO, KC_TRNS, MO(5)),

	/*LAYER 5 	[     ] [     ] [     ]
				[     ] [     ] [     ]
				[     ] [     ] [     ]
				[ to6 ] [     ] [  ^  ]	*/

	[5] = LAYOUT(KC_NO, KC_NO, KC_NO, \
				KC_NO, KC_NO, KC_NO, \
				KC_NO, KC_NO, KC_NO, \
				TO(6), KC_NO, KC_TRNS),

	/*LAYER 6 	[MAC2 ] [MAC3 ] [MAC4 ]
				[MAC5 ] [MAC6 ] [MAC7 ]
				[     ] [     ] [MAC1 ]
				[  ^  ] [MAC8 ] [ to0 ]	*/

	[6] = LAYOUT(MAC_P1, MAC_P2, MAC_P3, \
				MAC_P4, MAC_P5, MAC_P6, \
				KC_NO, KC_NO, MAC_BK, \
				KC_TRNS, MAC_DP, TO(0))

	//Continue to increase your layers by copy/pasting above layers, but be aware of the size limit of your firmware file, shortening keycode names or reducing the number of layers is an effective way of reducing size.

};

//No more code should go below this point, the "};" above closes out the entire keymap file, this is where having text software such as Sublime Text is very helpful to see when brackets are left floating.