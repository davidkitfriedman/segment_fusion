Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
 28.77      1.49     1.49                             abs_qual::var(int, int) (abs_qual.cpp:61 @ 4017ae)
 25.78      2.83     1.34                             abs_qual::var(int, int) (abs_qual.cpp:71 @ 401850)
 12.26      3.46     0.64                             abs_qual::var(int, int) (abs_qual.cpp:72 @ 40187e)
 11.49      4.06     0.60                             abs_qual::var(int, int) (abs_qual.cpp:74 @ 401889)
  8.69      4.51     0.45                             abs_qual::var(int, int) (abs_qual.cpp:78 @ 40189f)
  3.48      4.69     0.18                             abs_qual::var(int, int) (abs_qual.cpp:59 @ 4017e9)
  3.09      4.85     0.16                             abs_qual::var(int, int) (abs_qual.cpp:69 @ 4018b3)
  2.12      4.96     0.11                             abs_qual::var(int, int) (abs_qual.cpp:59 @ 4017a6)
  2.12      5.07     0.11                             abs_qual::var(int, int) (abs_qual.cpp:67 @ 4018bf)
  1.45      5.14     0.08                             abs_qual::var(int, int) (abs_qual.cpp:69 @ 401848)
  0.19      5.15     0.01                             grayscale(image<rgb>*) (misc.h:295 @ 4052ea)
  0.19      5.16     0.01                             grayscale(image<rgb>*) (misc.h:296 @ 405322)
  0.19      5.17     0.01                             abs_qual::var(int, int) (abs_qual.cpp:82 @ 4018cf)
  0.10      5.18     0.01                             random_rgb() (misc.h:120 @ 404dbb)
  0.10      5.18     0.01                             random_rgb() (misc.h:121 @ 404df5)
  0.00      5.18     0.00  1071126     0.00     0.00  image<rgb>::width() const (image.h:42 @ 40770a)
  0.00      5.18     0.00  1070080     0.00     0.00  uchar_max(unsigned char, unsigned char, unsigned char) (misc.h:125 @ 404df7)
  0.00      5.18     0.00  1070080     0.00     0.00  abs_qual::var(int, int) (abs_qual.cpp:31 @ 4016ec)
  0.00      5.18     0.00     1047     0.00     0.00  image<rgb>::height() const (image.h:45 @ 407724)
  0.00      5.18     0.00        4     0.00     0.00  pnm_read(std::basic_ifstream<char, std::char_traits<char> >&, char*) (pnmfile.h:65 @ 406979)
  0.00      5.18     0.00        4     0.00     0.00  std::ios_base::width(long) (ios_base.h:653 @ 40764a)
  0.00      5.18     0.00        2     0.00     0.00  image<float>::image(int, int, bool) (image.h:64 @ 404c70)
  0.00      5.18     0.00        2     0.00     0.00  image<float>::~image() (image.h:79 @ 40773e)
  0.00      5.18     0.00        1     0.00     0.00  grayscale(image<rgb>*) (misc.h:287 @ 40527a)
  0.00      5.18     0.00        1     0.00     0.00  loadPPM(char const*) (pnmfile.h:147 @ 407037)
  0.00      5.18     0.00        1     0.00     0.00  image<rgb>::image(int, int, bool) (image.h:64 @ 4078b0)
  0.00      5.18     0.00        1     0.00     0.00  image<rgb>::~image() (image.h:79 @ 407b18)
  0.00      5.18     0.00        1     0.00     0.00  abs_qual::brute() (abs_qual.cpp:155 @ 401b52)
  0.00      5.18     0.00        1     0.00     0.00  abs_qual::abs_qual(image<float>*, int) (abs_qual.cpp:22 @ 40168e)
  0.00      5.18     0.00        1     0.00     0.00  image<float>::width() const (image.h:42 @ 404c56)
  0.00      5.18     0.00        1     0.00     0.00  image<float>::height() const (image.h:45 @ 404c3c)
  0.00      5.18     0.00        1     0.00     0.00  std::operator|(std::_Ios_Openmode, std::_Ios_Openmode) (ios_base.h:120 @ 40762d)

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
