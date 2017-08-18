Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
 34.57      1.46     1.46                             abs_qual::square_var(int, int) (abs_qual.cpp:117 @ 4019b4)
 27.09      2.60     1.14                             abs_qual::square_var(int, int) (abs_qual.cpp:128 @ 401a84)
 26.25      3.70     1.11                             abs_qual::square_var(int, int) (abs_qual.cpp:127 @ 401a56)
  3.68      3.86     0.16                             abs_qual::square_var(int, int) (abs_qual.cpp:125 @ 401aad)
  2.85      3.98     0.12                             abs_qual::square_var(int, int) (abs_qual.cpp:125 @ 401a4e)
  1.78      4.05     0.08                             abs_qual::square_var(int, int) (abs_qual.cpp:115 @ 4019ac)
  1.43      4.11     0.06                             abs_qual::square_var(int, int) (abs_qual.cpp:115 @ 4019ef)
  0.71      4.14     0.03                             abs_qual::square_var(int, int) (abs_qual.cpp:123 @ 401ab9)
  0.48      4.16     0.02                             abs_qual::square_var(int, int) (abs_qual.cpp:113 @ 4019fb)
  0.24      4.17     0.01                             grayscale(image<rgb>*) (misc.h:296 @ 405322)
  0.24      4.18     0.01                             abs_qual::square_var(int, int) (abs_qual.cpp:88 @ 401909)
  0.24      4.19     0.01                             abs_qual::square_var(int, int) (abs_qual.cpp:90 @ 401929)
  0.24      4.20     0.01                             abs_qual::square_var(int, int) (abs_qual.cpp:113 @ 4019a4)
  0.24      4.21     0.01                             abs_qual::square_var(int, int) (abs_qual.cpp:121 @ 401a27)
  0.00      4.21     0.00  1071126     0.00     0.00  image<rgb>::width() const (image.h:42 @ 40770a)
  0.00      4.21     0.00  1070080     0.00     0.00  uchar_max(unsigned char, unsigned char, unsigned char) (misc.h:125 @ 404df7)
  0.00      4.21     0.00  1070080     0.00     0.00  abs_qual::square_var(int, int) (abs_qual.cpp:87 @ 4018f2)
  0.00      4.21     0.00     1047     0.00     0.00  image<rgb>::height() const (image.h:45 @ 407724)
  0.00      4.21     0.00        4     0.00     0.00  pnm_read(std::basic_ifstream<char, std::char_traits<char> >&, char*) (pnmfile.h:65 @ 406979)
  0.00      4.21     0.00        4     0.00     0.00  std::ios_base::width(long) (ios_base.h:653 @ 40764a)
  0.00      4.21     0.00        2     0.00     0.00  image<float>::image(int, int, bool) (image.h:64 @ 404c70)
  0.00      4.21     0.00        2     0.00     0.00  image<float>::~image() (image.h:79 @ 40773e)
  0.00      4.21     0.00        1     0.00     0.00  grayscale(image<rgb>*) (misc.h:287 @ 40527a)
  0.00      4.21     0.00        1     0.00     0.00  loadPPM(char const*) (pnmfile.h:147 @ 407037)
  0.00      4.21     0.00        1     0.00     0.00  image<rgb>::image(int, int, bool) (image.h:64 @ 4078b0)
  0.00      4.21     0.00        1     0.00     0.00  image<rgb>::~image() (image.h:79 @ 407b18)
  0.00      4.21     0.00        1     0.00     0.00  abs_qual::square_brute() (abs_qual.cpp:169 @ 401c36)
  0.00      4.21     0.00        1     0.00     0.00  abs_qual::abs_qual(image<float>*, int) (abs_qual.cpp:22 @ 40168e)
  0.00      4.21     0.00        1     0.00     0.00  image<float>::width() const (image.h:42 @ 404c56)
  0.00      4.21     0.00        1     0.00     0.00  image<float>::height() const (image.h:45 @ 404c3c)
  0.00      4.21     0.00        1     0.00     0.00  std::operator|(std::_Ios_Openmode, std::_Ios_Openmode) (ios_base.h:120 @ 40762d)

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.
 
 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
	   else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this 
	   function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
	   the function in the gprof listing. If the index is
	   in parenthesis it shows where it would appear in
	   the gprof listing if it were to be printed.

Copyright (C) 2012-2014 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.
