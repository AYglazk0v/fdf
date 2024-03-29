################################################

CC = gcc
FLAGS = -Wall -Wextra -Werror -O2 
INCL = ./includes/
MLX_DIR	= ./minilibx-linux/
CFLAGS = $(FLAGS) -I $(INCL) -I $(MLX_DIR)


################################################

NAME_FDF = fdf

################################################

PATH_SRC = src/
PATH_DRAW = src/draw/
PATH_UTILS = src/utils/
PATH_GNL = gnl/

################################################


SRC	=	init.c \
		main.c \
		readmap.c \
		rotate.c \
		mouse_evnt.c


UTILS	=	ft_split.c \
			utils_1.c \
			utils_2.c \
			utils_3.c

DRAW	=	draw_1.c \
			draw_2.c \
			draw.c

SRC_GNL	=	get_next_line_utils.c \
			get_next_line.c

################################################

SRC_FDF	=	$(addprefix $(PATH_SRC), $(SRC)) \
			$(addprefix $(PATH_DRAW), $(DRAW)) \
			$(addprefix $(PATH_UTILS), $(UTILS)) \
			$(addprefix $(PATH_GNL), $(SRC_GNL))


OBJ_FDF	=	$(SRC_FDF:.c=.o)

################################################

all : $(NAME_FDF)

$(NAME_FDF) : $(OBJ_FDF)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME_FDF) $(OBJ_FDF) -L $(MLX_DIR) -lmlx -lGL -lm -lX11 -lXext

clean:
	@rm -rf $(OBJ_FDF)
	@make clean -C $(MLX_DIR)

fclean: clean
	@rm -rf $(NAME_FDF)

re: fclean all

.PHONY: all re clean fclean step step2 step3 step4 step5 step6 step7 dance

################################################

define RIK_1
----------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------- 
---------------------------------------------------------------------------------------------------- 
---------------------------------------------------------------------------------------------------- 
---------------------------------------------------------------------------------------------------- 
-------------------------::-------/----------------------------------------------------------------- 
-------------------------+-::----/-/---------------------------------------------------------------- 
-------------------------/``.::-:-`-/--------------------------------------------------------------- 
-------------------------/````.::```/--::----------------------------------------------------------- 
-------------------/:::::/``..---------::----------------------------------------------------------- 
-------------------::``````---`````.-:.+------------------------------------------------------------ 
---------------------/-```/.``.--:::::o/::---------------------------------------------------------- 
--------------------::/.`:.``/+::/-.:://::---------------------------------------------------------- 
----------------:::-`````/```:`   -/    /----------------------------------------------------------- 
-----------------/::---``/```:`  /-:-  s/----------------------------------------------------------- 
-------------------:::-``/.``-/:::..::/o/----------------------------------------------------------- 
------------------/:-.``-:-``....``:-:.+------------------------------------------------------------ 
----------------------:::--.````````..`+------------------------------------------------------------ 
----------------------:/::::``````-.:/./------------------------------------------------------------ 
------------------------:+:/:.````.:/:/------------------------------------------------------------- 
--------------------::.````-:-:--..-/:-------------------------------------------------------------- 
-------------------:-    `--::-/o`:  ./------------------------------------------------------------- 
-------------------/    `: -.``./ `- --------------------------------------------------------------- 
-------------------/   `:  -.```/   :: /------------------------------------------------------------ 
-------------------:   :   -.```/    + /------------------------------------------------------------ 
-------------------:   -.  -.```/    .:/------------------------------------------------------------ 
-------------------/   `// :````/  --/ -------------------------:+osyhhhhys+:----------------------- 
-------------------o    /` :````/  -./  /---------------------/yhhhhhhhhhhhhhy+--------------------- 
-------------------o.   :  /````/    :` /--------------------ohhhyo+/:/+++oyhhhy:------------------- 
------------------/.:   : --````/    /  /-------------------shho-.`````..``.:shhh:------------------ 
------------------/ :   :`/`````/   -/  --------------------hh+.`````--..-.``.+hho------------------ 
-----------------/` :   `+-`````/  .-:   /------------------d/-.-..`::.   .-```ohs------------------ 
----------------:`  :    +``````:``---   /------------------y:   `:`-.    .-```:o+------------------ 
---------------:`   -`   :``````:`` :/   :------------------/`   `:.`.-..-.`````./------------------ 
-------------::     .:   :``````:`  //   -:-----------------:/...-.:--`:+``````/:------------------- 
------------::     -//   :....--+`  /:.   /------------------:-.```.-/sds.```./:-------------------- 
-----------::     +mmo   `/:hddd+`  /-:   /--------------------::..oys+-``..-:::-------------------- 
-----------/    `oyyhy    yshhy.-`  +-/   :----------------------::::::-----````:/------------------ 
----------/    -yyyyyh    oyyh.  : .:-+   .:-------------------------+````-.``````::---------------- 
---------/`   -hyyyyyh.   /yyyy: : :--:.   +------------------------::`:``:.```-```./--------------- 
---------:   -./yyyyy+:   -yyyyyo+ /---:   /------------------------+``.+./````/`````/:------------- 
--------/.   :  +yyyyyo    :/yyyyy++---/   :------------------------+```+/+````/``````/------------- 
--------+   :    oyyyys    : .oyyyyyo:-+   -:-----------------------/---/-+:---:```````/------------ 
--------/   :    `syyyh    :   :syyyyyo//--+-------------------------/./---+../````````./----------- 
--------/  -`     `syyh`   /    `/yyyyyys.-o-------------------------:`/---/``/`````````::---------- 
--------/  :       `syyo---/      -yyyyyo..::------------------------:`/---/``/``````````+---------- 
--------/  :        `yyy-..+`     `//syo.```::-----------------------:`/---/``/``````````/----------
--------/ `-         -yh/...--`   `/--+/+/`:./:----------------------:`/---/``/````````.-s:--------- 
--------:-`-     ```.-+h/.```//`   +---/yy-:./+----------------------:`/---/``/.....-:ohmmo--------- 
---------/ :  `---::---+ho-`:+/----+----+y-y.o-----------------------:`/---+``hhyhhdmmmmmm:--------- 
----------::.::---------hy://+----------oosh+------------------------:`/-/hy``dNNmmmmmmds:---------- 
----------:o/----------+yy+y/:----------shyy+-----------------------/.`-hmmo``/dmmmmmy/------------- 
-----------------------syyyy/-----------hyyh:----------------------:/ohhdmN+//+hmmdo---------------- 
-----------------------hyyh/-----------:hyyh-----------------------ymmmmmdmmmhsmy/------------------ 
----------------------oyyyy------------oyyyy----------------------/mmmmh+mmmmms:-------------------- 
----------------------yyyy+------------syyys-----------------------smmmmsdmmmh---------------------- 
---------------------:hyyh:------------yyyyo------------------------ommmmyhmmmh--------------------- 
---------------------+soyo-------------yssy/-------------------------/dmmmyhmmmh:------------------- 
---------------------/``+--------------+``+---------------------------:hmmmyymmmh:------------------ 
--------------------:o..+--------------o..o-----------------------------ymhy:ommmh------------------ 
--------------------dmddd/------------ymddmh+:---------------------------+:-/:/ho//----------------- 
-------------------+mmmmmmh+---------:mmmmmmmdo-----------------------::-`  `+:-..-/---------------- 
-------------------smmmmmmmmy--------:hddmmmmmms----------------------/-----/-`````/----------------
--------------------:////////------------:::::------------------------------::::::::----------------
---------------------------------------------------------------------------------------------------- 
----------------------------------------------------------------------------------------------------
endef

define RIK_2
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
-------------------------:--------/-----------------------------------------------------------------
-------------------------/-::----/-/----------------------------------------------------------------
-------------------------/``-::-::`-:---------------------------------------------------------------
-------------------------/````-:/```+---:-----------------------------------------------------------
-------------------/:::::+``...----.:--/:-----------------------------------------------------------
-------------------::``````---.````---`/------------------------------------------------------------
---------------------/.```:.`..-:::::/o/:-----------------------------------------------------------
--------------------::/.`:.``/+/:/--:://::----------------------------------------------------------
-----------------::-.````/```:`   -/`  `/-----------------------------------------------------------
----------------::::---``/```:   /-/.  o/-----------------------------------------------------------
-------------------::::``/```-:.---.::/o+-----------------------------------------------------------
------------------//-.``./-``..--``:-:.+------------------------------------------------------------
---------------------::::--.````````..`+------------------------------------------------------------
----------------------:+--:-``````-.-/./------------------------------------------------------------
-------------------------+:o:.````-:/:/-------------------------------------------------------------
------------------------::-/:-:----:::--------------------------------------------------------------
--------------------::.`  `-::./o.-::---------------------------------------------------------------
-------------------:-    `--.`.-/ .  ./-------------------------------------------------------------
-------------------/    `- -.```/ `-`-:-------------------------------------------------------------
-------------------/   `-  -.```/   -/`/------------------------------------------------------------
-------------------:   :   -.```/    `:/------------------------------------------------------------
-------------------:   -.  :.```/   `:./------------------------------------------------------------
-------------------/   `:/ :````/  .:: --------------------------/osyhhhhhyo/-----------------------
-------------------s    +  /````/    :` /----------------------ohhhhhhhhhhhhhho:--------------------
------------------/-.   : .:````/    /  /--------------------/yhhys+/::/++oshhhh+-------------------
------------------/ :   : :`````/   .+  /-------------------:hhs/.`````..-`.-ohhho------------------
-----------------/` :   -.:`````/  `::  --------------------+do-`````.--.--.``:hhd------------------
---------------::`  :   `/``````/ `-..   /------------------ss-..-.``::   `:```:hd------------------
-------------::`    :    /``````/ ` --   /------------------o/    .-`:`   `:```.oy------------------
-----------:-`      :`   /``````:   :/   :------------------/.    --`.-..--.`````/------------------
---------::`       :h:   :....../   /+   -:------------------+----.-:-`-/.`````-::------------------
--------::       `ohd+   ::yyyy//   //.   /-------------------:.```.-/ohy-````-/--------------------
--------/       .syyyo   `hhhd/ :  ---/   /--------------------::..+ys+:``..--::--------------------
-------/.      .yyyyys    yyyy. :  /--/   :-----------------------::-:------.``.::------------------
-------/      .yyyyyyd    oyyyy::  /--+   .:------------------------::`````````:`-/-----------------
-------:     .-.yyyyyd.   /syyyys. +--:.   +------------------------+``````:```/``./----------------
-------/     :  /yyyyy/   -`+yyyyy+:---:   /------------------------/``/```/```:.```::--------------
-------/    :    oyyyyo    : .syyyys:--/   :------------------------/``.o``/```.:````-/-------------
-------:-   :    `syyys    :  `+yyyyy+-+   -:-----------------------/:--+/`::--::`````-/------------
--------/  `-     .yyyy    :    -syyyys//--+-------------------------/./-:-`/../```````-/-----------
---------: :       -yyh`   /     -syyyyys.-o-------------------------/`:--+`/``/````````::----------
---------/`:        :yyo---/     --/syyyo..::------------------------/`:--::/``/`````````::---------
----------/-`        +yy-..+`    :---+yo.```::-----------------------/`:---:+``/``````````+---------
----------:-: `.--::::yh/...--`  :----::+/`:`/:----------------------/`:----+``/```````-:oh---------
-----------/+::-------/h/.```/+--/-----/yy-:./+----------------------/`:----/``/``..:oydmmm---------
------------+----------+ho-`:+:---------+y-y.o-----------------------/`:---/s``hsyhdmmmmmms---------
------------------------hy://+----------oosh+------------------------/`:-/ymd``dNNmmmmmds/----------
-----------------------+yy+y/:----------shyy+-----------------------/-`-ymmm+`.:dmmmmdo-------------
-----------------------syyyy/-----------hyyh------------------------/ohhhmmNoo/+hmmy/---------------
-----------------------hyyh/-----------:hyyh-----------------------smmmmmhdmmmdyms:-----------------
----------------------oyyyy------------oyyyy-----------------------hmmmm/ymmmmdo--------------------
----------------------yyyy+------------syyys-----------------------:hmmmd+mmmms---------------------
---------------------:hyyh:------------yyyys-------------------------hmmmdommmm+--------------------
---------------------+soyo-------------yssy/--------------------------ymmmdsmmmm/-------------------
---------------------/``+--------------+``+----------------------------smmmdommmm/------------------
--------------------:o..+-------------:o..o-----------------------------omhy:+mmmd------------------
--------------------dmddd/------------ymddmy+:---------------------------+:-/:/ho//-----------------
-------------------+mmmmmmh+---------:mmmmmmmdo-----------------------::-`  `+:-..-/----------------
-------------------smmmmmmmmy--------/hddmmmmmms----------------------/-----/-`````/----------------
--------------------:///////:------------:::::------------------------------::::::::----------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
endef

define RIK_3
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
-------------------------:--------/-----------------------------------------------------------------
-------------------------+-::----/-/----------------------------------------------------------------
-------------------------/``.::-::`-/---------------------------------------------------------------
-------------------------/````.::```/--::-----------------------------------------------------------
-------------------/:::::+``..---------::-----------------------------------------------------------
-------------------::``````---.````.--`+------------------------------------------------------------
---------------------/-```/.``.---::::o/::----------------------------------------------------------
--------------------::/.`:.``/+///--/://::----------------------------------------------------------
----------------:::-`````/```:`   -/`   /-----------------------------------------------------------
----------------::::---``/```:   /-/.  o/-----------------------------------------------------------
-------------------:::-``/```-/-::-.::/o+-----------------------------------------------------------
------------------/:-.``-:-``....``:-:.+------------------------------------------------------------
---------------------::::--.````````..`+------------------------------------------------------------
----------------------:/--::``````-.:/./------------------------------------------------------------
----------------------:::+-+:.````.:/:/-------------------------------------------------------------
---------------------:.````-:-:--..-/:--------------------------------------------------------------
-------------------::    `--::-/o`:` ./-------------------------------------------------------------
-------------------/    `: --`../ `- ---------------------------------------------------------------
-------------------/   `:  --```/   :: /------------------------------------------------------------
-------------------:   :   -.```/    + /------------------------------------------------------------
-------------------:   -.  -.```/    .:/------------------------------------------------------------
-------------------/   `/: :.```/  --/ -:-------------------------/osyhhhhhys+----------------------
-------------------o    /` :````/  -./  /-----------------------+hhhhhhhhhhhhhhs:-------------------
-------------------o.   :  /````/    :` /---------------------/yhhyo/:--:+++shhhho------------------
------------------/.:   : --````/    /  /---------------------hhy:.``````.-..-ohhhs-----------------
------------------/ :   -`/`````/   -/  ---------------------:d/-..```.-..--.``:hhh:----------------
-----------------:` :   `+-`````/  .-:   /-------------------oy.``.-``:/   `:```:hh/----------------
------------:-.``   :    +``````:``-.-   /-------------------+.    .-`:`   `:```.yh-----------------
----------:.`       -`   :``````:`` :/   /-------------------/:````--`.--..-.```..+-----------------
--------:-         `::   :``````:`  //   -:-------------------/-...`:-..:/``````-::-----------------
--------:         :hs+   :.`````/`  /:.   /--------------------/.``.:/oydo````.-:-------------------
-------/        `odmms   `+ssoo/+  `/-/   /---------------------::--oo+:.``..--:::------------------
-------/       .syyyyy    hddds`:  :--/   :------------------------:::-------````/------------------
-------/      -yyyyyyh    oyyh` :  /--+   .:------------------------+````````````::-----------------
-------/     .+yyyyyhh.   /yyyy::  +--:.   +------------------------/`.``````-```-:-----------------
-------/     : /yyyyyy:   -yyyyyy.`/---:   /------------------------/`/``````/```-+-----------------
-------/    -`  +yyyyyo    :/yyyyys:---/   :------------------------/`--`````/```-:/----------------
--------:   :    oyyyys    : .oyyyyyo:-+   .:-----------------------//-+`````::-::../---------------
--------/   :    `syyyh    :   :syyyyyo:/--+-------------------------+`./`````/`/.``.::-------------
---------: `-     `syyh`   /    `/yyyyyys.-o-------------------------+``+:````/`/.````.::-----------
---------/``-      `syyo---/     `+oyyyyo..::------------------------+``/::```/`/.``````-/:---------
----------: :       `yyy-..+`    `/-/syo.```::-----------------------+``/-::.`/`/.``````.sd/--------
-----------:/  ``.---/yy/...--`   /---+/+/`:./:----------------------+``/---:-/`/.````-+dmmm/-------
------------+/:-:-----+h/.```/+-``/----/yy-:./+----------------------+``/----:/`/--:+ydmmmmm+-------
-------------/---------+ho-`:+:--::-----+y-y.o-----------------------+``/--:oh+`/mmNmmmmmmh/--------
------------------------hy///+----------oosh+------------------------+``+:sdmm+`-mNmmmmmh+----------
-----------------------+yy+y/:----------shyy+------------------------/`.:mmmmm..-/mmmms/------------
-----------------------syyyy/-----------hyyh:-----------------------+/hmdmmmyyhs/omdo---------------
-----------------------hyyh/-----------:hyyh------------------------smmmmho/dmmmms/-----------------
----------------------oyyyy------------+yyyy------------------------:mmmms-hmmmd/-------------------
----------------------yyyy+------------syyyy-------------------------+mmmm/+mmmm:-------------------
---------------------:hyyh:------------yyyys--------------------------+mmmd:ymmmy-------------------
---------------------+soys-------------yssy/---------------------------smmmy:mmmm+------------------
---------------------/``+--------------+``+-----------------------------ymmm+ommmd------------------
--------------------:o..+--------------o..o-----------------------------:hyo/-ymmms-----------------
--------------------dmddd/------------smddmy+----------------------------::./:-yo:+-----------------
-------------------+mmmmmmh+---------:mmmmmmmdo-----------------------::-`  `+:-..-/----------------
-------------------smmmmmmmmy--------:hdmmmmmmms----------------------/-----/-`````/----------------
--------------------:////++//------------:::::------------------------------::::::::----------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
endef

export RIK_1
export RIK_2
export RIK_3

step step2 step3 step4 step5 step6 step7:
	@clear
	@echo "$$RIK_1"
	@sleep 0.15
	@clear
	@echo "$$RIK_2"
	@sleep 0.15
	@clear
	@echo "$$RIK_3"
	@sleep 0.15
	@clear
	@echo "$$RIK_2"
	@sleep 0.15

dance: step	step2 step3	step4 step5 step6 step7

################################################
