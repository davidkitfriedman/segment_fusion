import os
names=["car", "friends", "husky", "olympics2016"]
for name in names:
    print "Running on " + name
    os.system("python run_segment_"+name+".py")
    print

