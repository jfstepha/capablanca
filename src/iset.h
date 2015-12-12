/*
   Copyright (C) Andrew Tridgell 2002
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

/*
  structures for the iset command
*/

GENSTRUCT struct ivariables {
	unsigned startpos;
	unsigned ms;
	unsigned lock;
	unsigned compressmove;
	unsigned defprompt;
	unsigned seekremove;
	unsigned block;
	unsigned gameinfo;
	unsigned pendinfo;
	unsigned graph;
	unsigned seekinfo;
	unsigned extascii;
	unsigned showserver;
	unsigned nohighlight;
	unsigned vthighlight;
	unsigned pin;
	unsigned pinginfo;
	unsigned boardinfo;
	unsigned extuserinfo;
	unsigned audiochat;
	unsigned seekca;
	unsigned showownseek;
	unsigned premove;
	unsigned smartmove;
	unsigned movecase;
	unsigned nowrap;
	unsigned allresults;
	unsigned singleboard;
	unsigned suicide;
	unsigned crazyhouse;
	unsigned losers;
	unsigned wildcastle;
	unsigned fr;
	unsigned atomic;
	unsigned xml;
};

