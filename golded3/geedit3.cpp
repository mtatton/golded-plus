
//  ------------------------------------------------------------------
//  GoldED+
//  Copyright (C) 1990-1999 Odinn Sorensen
//  Copyright (C) 1999-2000 Alexander S. Aganichev
//  ------------------------------------------------------------------
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License as
//  published by the Free Software Foundation; either version 2 of the
//  License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston,
//  MA 02111-1307 USA
//  ------------------------------------------------------------------
//  $Id$
//  ------------------------------------------------------------------
//  OS/2 clipboard to/from edit paste buffer.
//  ------------------------------------------------------------------

#include <golded.h>
#include <geedit.h>
#include <gutlclip.h>

void IEclass::Clip2Buf() {

  gclipbrd clipbrd;

  if(not clipbrd.openread())
    return;

  int tabsz = CFG->disptabsize ? CFG->disptabsize : 1;
  __extension__ char spaces[tabsz+1];
  memset(spaces, ' ', tabsz);
  spaces[tabsz] = NUL;

  // Allocate paragraph read buffer
  char *buf = (char *)throw_malloc(EDIT_PARABUFLEN);
  Line *__line = NULL;

  Undo->undo_enabled = NO;
  
  // Read paragraphs
  while(clipbrd.read(buf, EDIT_PARABUFLEN-6)) {

    // Replace tabs
    char *ht = buf;
    while((ht = strchr(ht, '\t')) != NULL) {
      int rposn = ht-buf;
      int rstart = rposn%tabsz+1;
      *ht = ' ';
      if(tabsz > rstart)
        strins(spaces+rstart, buf, rposn);
    }

    // Copy the paragraph to the new line and retype it
    __line = insertlinebelow(__line, buf);
    if(Edit__pastebuf == NULL)
      Edit__pastebuf = __line;
    setlinetype(__line);
  }
  Undo->undo_enabled = YES;
  throw_free(buf);
  clipbrd.close();
}


void IEclass::Buf2Clip() {

  gclipbrd clipbrd;
  Line *_bufline;
  string clipdata;

  for(_bufline = Edit__pastebuf; _bufline; _bufline = _bufline->next)
    if(not _bufline->txt.empty()) {
      clipdata += _bufline->txt;
      if(*(clipdata.end()-1) == '\n')
        clipdata.replace(clipdata.end()-1, clipdata.end(), "\r\n");
    }

  clipbrd.writeclipbrd(clipdata.c_str());
}
