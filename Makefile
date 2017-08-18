
cellalg/cellalg.o: cellalg/cellalg.h cellalg/cellalg.cpp
	g++ -c -I. -I./cellalg cellalg/cellalg.cpp -o cellalg/cellalg.o

abs_qual/abs_qual.o: abs_qual/abs_qual.cpp abs_qual/abs_qual.h image.h
	g++ -c -I. -I./abs_qual abs_qual/abs_qual.cpp -o abs_qual/abs_qual.o

abs_qual/abs_qual_profiled.o: abs_qual/abs_qual.cpp abs_qual/abs_qual.h image.h
	g++ -c -g -pg -I. -I./abs_qual abs_qual/abs_qual.cpp -o abs_qual/abs_qual_profiled.o

GCoptimization1.1/GCoptimization.o: GCoptimization1.1/Energy.h GCoptimization1.1/Graph.h GCoptimization1.1/GCoptimization.h GCoptimization1.1/GCoptimization.cpp
	g++ -c -I. -I./GCoptimization1.1 GCoptimization1.1/GCoptimization.cpp -o GCoptimization1.1/GCoptimization.o	

GCoptimization1.1/graph.o: GCoptimization1.1/Graph.h GCoptimization1.1/graph.cpp
	g++ -c -I. -I./GCoptimization1.1 GCoptimization1.1/graph.cpp -o GCoptimization1.1/graph.o

GCoptimization1.1/LinkedBlockList.o: GCoptimization1.1/LinkedBlockList.h GCoptimization1.1/LinkedBlockList.cpp
	g++ -c -I. -I./GCoptimization1.1 GCoptimization1.1/LinkedBlockList.cpp -o GCoptimization1.1/LinkedBlockList.o

GCoptimization1.1/maxflow.o: GCoptimization1.1/Graph.h GCoptimization1.1/maxflow.cpp
	g++ -c -I. -I./GCoptimization1.1 GCoptimization1.1/maxflow.cpp -o GCoptimization1.1/maxflow.o

segment_fusion: segment.cpp segment-image.h segment-graph.h disjoint-set.h misc.h cellalg/cellalg.o abs_qual/abs_qual.o  GCoptimization1.1/GCoptimization.o  GCoptimization1.1/graph.o  GCoptimization1.1/LinkedBlockList.o GCoptimization1.1/maxflow.o   
	g++ -I. -I./cellalg -I./abs_qual -I./GCoptimization1.1 -lm segment.cpp cellalg/cellalg.o abs_qual/abs_qual.o GCoptimization1.1/GCoptimization.o  GCoptimization1.1/graph.o  GCoptimization1.1/LinkedBlockList.o GCoptimization1.1/maxflow.o -o segment_fusion

clean:
	rm cellalg/cellalg.o abs_qual/abs_qual.o GCoptimization1.1/GCoptimization.o GCoptimization1.1/graph.o GCoptimization1.1/LinkedBlockList.o GCoptimization1.1/maxflow.o segment_fusion

test/test_abs_qual: test/test_abs_qual.cpp abs_qual/abs_qual.o
	g++ -I. -I./abs_qual abs_qual/abs_qual.o test/test_abs_qual.cpp -o test/test_abs_qual

test/enlarge: test/enlarge.cpp image.h pnmfile.h 
	g++ -I. test/enlarge.cpp -o test/enlarge

test/count_color: test/count_color.cpp image.h pnmfile.h 
	g++ -I. test/count_color.cpp -o test/count_color

test/test_brutevcell: test/test_brutevcell.cpp cellalg/cellalg.o image.h pnmfile.h
	g++ -I. -I./cellalg cellalg/cellalg.o test/test_brutevcell.cpp -o test/test_brutevcell 


test/compare_qual: test/compare_qual.cpp abs_qual/abs_qual.o image.h pnmfile.h
	g++ -I. -I./abs_qual abs_qual/abs_qual.o test/compare_qual.cpp -o test/compare_qual 

test/profile_abs_qual: test/profile_abs_qual.cpp image.h pnmfile.h misc.h abs_qual/abs_qual.h abs_qual/abs_qual.cpp abs_qual/abs_qual_profiled.o
	g++ -pg -g -I. -I./abs_qual abs_qual/abs_qual_profiled.o test/profile_abs_qual.cpp -o test/profile_abs_qual
