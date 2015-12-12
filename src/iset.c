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


#include "includes.h"

/*
  set a boolean ivar
*/
static int iset_bool(int p, unsigned *v, const char *var, const char *value)
{
	if (strcmp(value, "1") == 0) {
		*v = 1;
		pprintf(p, "%s set\n", var);
	} else if (strcmp(value, "0") == 0) {
		*v = 0;
		pprintf(p, "%s unset\n", var);
	} else {
		pprintf(p, "Bad value '%s' given for ivariable '%s'.\n", value, var);
	}
	return COM_OK;
}

/*
  support the iset command
*/
int com_iset(int p, param_list param)
{
	struct player *pp = &player_globals.parray[p];
	char *var = param[0].val.word;
	char *value = param[1].val.string;
	struct ivariables *iv;

	iv = &pp->ivariables;

	if (iv->lock) {
		pprintf(p,"Cannot alter: Interface setting locked.\n");
		return COM_OK;
	}

	if (strcasecmp(var,"ms") == 0) {
		return iset_bool(p, &iv->ms, var, value);
	} else if (strcasecmp(var,"lock") == 0) {
		return iset_bool(p, &iv->lock, var, value);
	} else if (strcasecmp(var,   "startpos") == 0) {
		return iset_bool(p, &iv->startpos, var, value);
	} else if (strcasecmp(var,  "compressmove") == 0) {
		return iset_bool(p, &iv->compressmove, var, value);
	} else if (strcasecmp(var,  "defprompt") == 0) {
		return iset_bool(p, &iv->defprompt, var, value);
	} else if (strcasecmp(var,  "seekremove") == 0) {
		return iset_bool(p, &iv->seekremove, var, value);
	} else if (strcasecmp(var,  "startpos") == 0) {
		return iset_bool(p, &iv->startpos, var, value);
	} else if (strcasecmp(var,  "block") == 0) {
		return iset_bool(p, &iv->block, var, value);
	} else if (strcasecmp(var,  "gameinfo") == 0) {
		return iset_bool(p, &iv->gameinfo, var, value);
	} else if (strcasecmp(var,  "pendinfo") == 0) {
		return iset_bool(p, &iv->pendinfo, var, value);
	} else if (strcasecmp(var,  "graph") == 0) {
		return iset_bool(p, &iv->graph, var, value);
	} else if (strcasecmp(var,  "seekinfo") == 0) {
		return iset_bool(p, &iv->seekinfo, var, value);
	} else if (strcasecmp(var,  "extasciii") == 0) {
		return iset_bool(p, &iv->extascii, var, value);
	} else if (strcasecmp(var,  "showserver") == 0) {
		return iset_bool(p, &iv->showserver, var, value);
	} else if (strcasecmp(var,  "nohighlight") == 0) {
		return iset_bool(p, &iv->nohighlight, var, value);
	} else if (strcasecmp(var,  "vthighlight") == 0) {
		return iset_bool(p, &iv->vthighlight, var, value);
	} else if (strcasecmp(var,  "pin") == 0) {
		return iset_bool(p, &iv->pin, var, value);
	} else if (strcasecmp(var,  "pinginfo") == 0) {
		return iset_bool(p, &iv->pinginfo, var, value);
	} else if (strcasecmp(var,  "boardinfo") == 0) {
		return iset_bool(p, &iv->boardinfo, var, value);
	} else if (strcasecmp(var,  "extuserinfo") == 0) {
		return iset_bool(p, &iv->extuserinfo, var, value);
	} else if (strcasecmp(var,  "audiochat") == 0) {
		return iset_bool(p, &iv->audiochat, var, value);
	} else if (strcasecmp(var,  "seekca") == 0) {
		return iset_bool(p, &iv->seekca, var, value);
	} else if (strcasecmp(var,  "showownseek") == 0) {
		return iset_bool(p, &iv->showownseek, var, value);
	} else if (strcasecmp(var,  "premove") == 0) {
		return iset_bool(p, &iv->premove, var, value);
	} else if (strcasecmp(var,  "smartmove") == 0) {
		return iset_bool(p, &iv->smartmove, var, value);
	} else if (strcasecmp(var,  "movecase") == 0) {
		return iset_bool(p, &iv->movecase, var, value);
	} else if (strcasecmp(var,  "nowrap") == 0) {
		return iset_bool(p, &iv->nowrap, var, value);
	} else if (strcasecmp(var,  "allresults") == 0) {
		return iset_bool(p, &iv->allresults, var, value);
	} else if (strcasecmp(var,  "singleboard") == 0) {
		return iset_bool(p, &iv->singleboard, var, value);
	} else if (strcasecmp(var,  "suicide") == 0) {
		return iset_bool(p, &iv->suicide, var, value);
	} else if (strcasecmp(var,  "crazyhouse") == 0) {
		return iset_bool(p, &iv->crazyhouse, var, value);
	} else if (strcasecmp(var,  "losers") == 0) {
		return iset_bool(p, &iv->losers, var, value);
	} else if (strcasecmp(var,  "wildcastle") == 0) {
		return iset_bool(p, &iv->wildcastle, var, value);
	} else if (strcasecmp(var,  "xml") == 0) {
		return iset_bool(p, &iv->xml, var, value);
	} else {
		pprintf(p,"No such ivariable \"%s\".\n", var);
	}

	return COM_OK;
}

int com_ivar(int p)
{
	pprintf(p, "Interface variables\n");
	struct ivariables *iv;
	struct player *pp = &player_globals.parray[p];

	iv = &pp->ivariables;
	pprintf(p, "Interface variable settings of %s:\n\n", pp->name);
	pprintf(p, "compressmove=%u      defprompt=%u    lock=%u          ms=%u\n", iv->compressmove, iv->defprompt, iv->lock, iv->ms);
	pprintf(p, "seekremove=%u        startpos=%u     block=%u         gameinfo=%u\n", iv->seekremove, iv->startpos, iv->block, iv->gameinfo);
	pprintf(p, "pendinfo=%u          graph=%u        seekinfo=%u      extascii=%u\n", iv->pendinfo, iv->graph, iv->seekinfo, iv->extascii);
	pprintf(p, "showserver=%u        nohighlight=%u  vthighlight=%u   pin=%u\n", iv->showserver, iv->nohighlight, iv->vthighlight, iv->pin);
	pprintf(p, "pinginfo=%u          boardinfo=%u    extuserinfo=%u   audiochat=%u\n", iv->pinginfo, iv->boardinfo, iv->extuserinfo, iv->audiochat);
	pprintf(p, "seekca=%u            showownseek=%u  premove=%u       smartmove=%u\n", iv->seekca, iv->showownseek, iv->premove, iv->smartmove);
	pprintf(p, "movecase=%u          nowrap=%u       allresults=%u    singleboard=%u\n", iv->movecase, iv->nowrap, iv->allresults, iv->singleboard);
	pprintf(p, "suicide=%u           crazyhouse=%u   losers=%u        wildcastle=%u\n", iv->suicide, iv->crazyhouse, iv->losers, iv->wildcastle);
	pprintf(p, "fr=%u                atomic=%u       xml=%u\n", iv->fr, iv->atomic, iv->xml);
	pprintf(p, "Note many of these are not implemented yet\n");
	return COM_OK;

}
