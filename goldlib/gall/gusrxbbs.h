//  This may look like C code, but it is really -*- C++ -*-

//  ------------------------------------------------------------------
//  The Goldware Library
//  Copyright (C) 1990-1999 Odinn Sorensen
//  ------------------------------------------------------------------
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Library General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Library General Public License for more details.
//
//  You should have received a copy of the GNU Library General Public
//  License along with this program; if not, write to the Free
//  Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
//  MA 02111-1307, USA
//  ------------------------------------------------------------------
//  $Id$
//  ------------------------------------------------------------------
//  AdeptXBBS derived userfile class.
//  ------------------------------------------------------------------

#ifndef __gusrxbbs_h
#define __gusrxbbs_h


//  ------------------------------------------------------------------

#include <gfile.h>
#include <gusrbase.h>
#include <gtimall.h>


//  ------------------------------------------------------------------

#if defined(GOLD_CANPACK)
#pragma pack(1)
#endif


//  ------------------------------------------------------------------
//  AdeptXBBS structure for "Users" file

// The following flags are used for the 'user.attribs' bits.
#define U_ANSI            0x00000001  // Ansi Movement
#define U_COLOR           0x00000002  // Ansi Color
#define U_HIGHASCII       0x00000004  // High Ascii
#define U_NOMORE          0x00000008  // No? More? Prompts
#define U_NOCLEAR         0x00000010  // Don't Clear Screens
#define U_COLD            0x00000020  // No Hot Keys
#define U_NOSHOWADDRESS   0x00000040  // Don't show address in user list
#define U_NOSHOWPHONE     0x00000080  // Don't show phone numbers in user list
#define U_NOSHOWREAL      0x00000100  // Don't show real names in user list
#define U_NOKILL          0x00000200  // User cannot be killed/deleted
#define U_DELETED         0x00000400  // User marked as deleted
#define U_EXPERT          0x00000800  // User set for expert mode
#define U_TWIT            0x00001000  // User is a twit!
#define U_NEWFILES        0x00002000  // New files search at logon
#define U_NEWMSGS         0x00004000  // New message search at logon
#define U_DLNEWMSGS       0x00008000  // Auto download mail packets at logon
#define U_DLNEWFILELIST   0x00010000  // Auto download new file list at logon
#define U_SEENEWS         0x00020000  // Sees new news
#define U_ASKDL           0x00040000  // Ask logoff before download
#define U_NOVICE          0x00080000  // User set to novice
#define U_NOROLL          0x00100000  // no rolling prompts (obsolete)
#define U_POINTONLY       0x00200000  // Fidonet point mail only
#define U_LOCKEDOUT       0x00400000  // User locked out
#define U_AVAILABLE       0x00800000  // Available for multi-node chat
#define U_LISTPROTECTED   0x01000000  // Not shown in user list
#define U_MISCNEWSOK      0x02000000  // Sees misc. news
#define U_LIMITFLIST      0x04000000  // Limit file list to current area
#define U_EBCDIC          0x08000000  // EBCDIC <-> ASCII Conversion
#define U_VERIFIED        0x10000000  // user call back verified, turn this off, they get verified again.. (if BBS verifies)
#define U_ANSITE2         0x20000000  // User supports Ansi-TE2 Special Chars
#define U_RIPSCRIPT       0x40000000  // User has RIP Support
#define U_AVATAR          0x80000000  // User has Avatar Support

// The following flags are used for 'user.attribs2' bits.
#define U2_FSE            0x00000001  // User Full Screen Message Editor
#define U2_OFF_AFTER_MAIL 0x00000002  // Log off after mail download
#define U2_MONITOR_MAIL   0x00000004  // Monitor mail export/packing
#define U2_INT_NEW_FILES  0x00000008  // include new files in mail packet
#define U2_INC_BULLETS    0x00000010  // include bulletins in mail packet
#define U2_INC_WELCOME    0x00000020  // include welcome screen in mail packet
#define U2_DEFAULT_QWK    0x00000040  // Default use to QWK mail
#define U2_DEFAULT_FIDO   0x00000080  // Default use to Fidonet Point Mail
#define U2_DEFAULT_TEXT   0x00000100  // Default to text export
#define U2_DEFAULT_BLUE   0x00000200  // Default to Bluewave Mail
#define U2_AVTANS         0x00000400  // Can handle both ANSI and Avatar
#define U2_8DOT3          0x00000800  // Convert long names to 8.3 names

struct XbbsUsers {
  char  name[36];           // Users Name
  char  handle[36];         // Users Handle
  char  address[60];        // Address line 1
  char  address1[60];       // Address line 2
  char  address2[60];       // Address line 3
  char  city[20];           // Users City/County
  char  state[5];           // Users State
  char  zipcode[10];        // Users ZipCode
  char  home_phone[21];     // Users home phone number
  char  data_phone[21];     // Users data phone number
  char  fax_phone[21];      // Users fax phone number
  char  bus_phone[21];      // Users business/office number
  char  interests[78];      // Interest Line
  char  SysOpComment[78];   // Room for Sysops comment
  ushort banktime;           // Time in the bank
  ushort computer_type;      // Computer type
  long  userid;             // User ID
  short  pointid;            // Point Mail ID
  time_t initial_logon;      // Time/Date of initial logon
  time_t expires;            // Time/Date user expires
  time_t last_logon;         // Time/Date of last logon
  time_t logon_today;        // Last time the user logged on today
  short  birthyear;          // Birth Year
  char  birthmonth;         // Birth Month
  char  birthday;           // Birth day
  char  gender;             // Gender
  long  credit;             // User credit
  long  minlimit;           // Minimum limit
  long  group;              // Group number the user belongs to
  long  currlastread;       // Last read pointer for current area
  long  time_today;         // Number of minutes user used today
  long  time_per_day;       // Time limit per day
  long  time_per_call;      // Time limit per call
  long  numcalls;           // Number of total calls user made to BBS
  long  ulnum;              // Total number of uploads
  long  dlnum;              // Total number of downloads
  long  ulk;                // Total uploads in K-bytes
  long  dlk;                // Total downloads in K-bytes
  long  uktoday;            // Uploads in K-bytes made today
  long  dktoday;            // Download in k-bytes made today
  long  ukperday;           // Max k-bytes user can upload a day
  long  dkperday;           // Max k-byes a user can download a day
  long  numposts;           // Number of messages ever written
  long  security1;          // Security level #1
  long  security2;          // Security level #2
  long  flags1;             // Sysop definable 32 flags
  long  flags2;             // Sysop definable 32 flags
  long  attribs;            // User attributes
  long  attribs2;           // User attributes
  short  length;             // Screen length
  short  width;              // Screen width
  short  lastmsgarea;        // Last message area user was in
  short  lastfilearea;       // Last file area user was in
  char  lastprotocol;       // Last protocol user chose
  char  lastarchiver;       // Last archiver user chose
  long  forsysop;           // unused
  char  interface_;          // obsolete
  char  exp;                // unused
  short  leech_percent;      // File leech ratio
  short  maxbanktime;        // Maximum time user can have in bank
  short  timecredit;         // Current time user has credit for
  short  callstoday;         // Number of calls user made to BBS today
  long  totalminsever;      // Total minutes users has used ever
  long  netmaildebits;      // Total spent on NetMail
  time_t lastpwchange;       // Time/Date of last password change
  time_t lastlistednewfile;  // Time/Date user last listed new files
  ulong filekcredit;        // Amount of file k-byte credit user has
  char  unixid[8];          // Users Unix Specific ID
  byte _unused[94];        // reserved for future use
  byte mailtags[128];      // Message areas tagged for off-line mail
  byte usermsg[128];       // Message areas user can access
  byte userfile[128];      // File areas user can access
  ulong passwordcrc;        // User password CRC
  ulong passwordcrc2;       // User password CRC2
  ushort max_mail_pkt;       // Max msgs to pack for off-line mail
  char  reasked;            // Has user answered the ReAsk questionairre
  char  reserved[75];       // reserved for future user
};


//  ------------------------------------------------------------------

#if defined(GOLD_CANPACK)
#pragma pack()
#endif


//  ------------------------------------------------------------------
//  AdeptXBBS userfile class

class XbbsUser : public GUser {

public:

  uint maxindex;
  int firstread;
  XbbsUsers* record;
  
  XbbsUser();
  ~XbbsUser();

  int  isvalid();
  int  read();

  void  recinit(const char* __name);
  void  add(const char* __name);
};


//  ------------------------------------------------------------------

#endif

//  ------------------------------------------------------------------
