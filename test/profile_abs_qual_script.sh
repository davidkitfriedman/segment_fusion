./profile_abs_qual ~/segment_fusion/images/friends.ppm 7 main  
mv gmon.out main.out
./profile_abs_qual ~/segment_fusion/images/friends.ppm 7 brute
mv gmon.out brute.out
./profile_abs_qual ~/segment_fusion/images/friends.ppm 7 square_brute
mv gmon.out square_brute.out

gprof -p --line profile_abs_qual main.out         > main.profile 
gprof -p --line profile_abs_qual brute.out        > brute.profile 
gprof -p --line profile_abs_qual square_brute.out > square_brute.profile 
