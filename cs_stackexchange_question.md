I took a tangent from a [student
project](https://github.com/davidkitfriedman/segment_fusion/blob/master/texfiles/segment_fusion.pdf)
I had done a number of years ago and spent some time studying distance
functions.

I found this [textbook on data
mining](https://catalog.lib.ncsu.edu/record/NCSU3496291) which includes a
chapter on Similarity and Distances (chapter 3 of [_Data Mining The Textbook_
by Charu
C. Aggarwal](https://books.google.com/books?id=cfNICAAAQBAJ&printsec=frontcover&dq=data+mining+the+textbook&hl=en&sa=X&ved=0ahUKEwjXrILElerVAhXBVyYKHXb2Ao0Q6AEIKDAA#v=onepage&q&f=fal))

And so the text says:

>Sometimes, data analysts use the Euclidean function as a “black box” without
 much thought about the overall impact of such a choice. It is not uncommon
 for an inexperienced analyst to invest significant effort in the algorithmic
 design of a data mining problem, while treating the distance function
 subroutine as an afterthought. This is a mistake. 

And so there are a number of sections addressing quantitative data,
categorical, text, etc. 

I'd be curious about how distance functions are used in similar and different ways
across varied fields such as data mining, machine learning, computer vision, 
natural language processing, error control codes, or for example in specific 
applications like spell checkers. 

On the one hand, in my independent study, I saw various passages speaking about 
the necessity of applying domain knowledge. 

From 3.6 Supervised Similarity Functions of the above mentioned book:

>In practice, the relevance of a feature or the choice of distance function
heavily depends on the domain at hand.

Also in An [Introduction to Statistical Learning with Applications in R](https://books.google.com/books?id=qcI_AAAAQBAJ&dq=introduction+to+statistical+learning+in+R&source=gbs_navlinks_s) they mention:

>The choice of dissimilarity measure is very important, as it has a strong
effect on the resulting dendrogram. In general, careful attention should be
paid to the type of data being clustered and the scientific question at hand.
These considerations should determine what type of dissimilarity measure
is used for hierarchical clustering

On the other hand I took a brief look at [this Ph.D. thesis](http://ofirpele.droppages.com/ofirpele_phd_thesis.pdf) by [Ofir Pele](http://ofirpele.droppages.com/)
on distance functions, and so at the beginning it says:

>Our proposed methods have been successfully used both by computer 
vision researchers and by researchers in other fields. The success of
the methods in other fields is probably because the noise characteristics in those
fields are similar to image noise characteristics.

which suggested to me that there could be some overlap in different cases; however, I haven't read those papers in detail. 

Anyway, the question is: what are similarities and differences in how distance functions are used among disparate fields, and in what ways do those similarities and differences arise. 

## Few Thoughts on this Question ##

I thought to myself this may be a bit of an unusual question. After all people don't generally study looping in Java, Python, Lisp and Prolog and then go on to study variable declaration in five other programming languages. People more often study one particular programming language as a whole not a certain construct in multiple ones. But on the other hand within programming languages as an academic discipline at universities people might certainly talk about similarities and dissimilarities. Those very similarities and differences could be seen in light of differences as to whether the code is (usually) interpreted or compiled, or whether it tends to favor an imperative style or a recursive one. One might also seek to see how various characteristics developed within the evolution of programming languages throughout history and how different programming languages built on earlier ones. Certain design decisions could very well derive from certain goals: ease of learning, readability, speed, verifiability. 

Similarly in human languages people don't usually study a set of words or phrases in multiple human langauges but usually study one particular human language as a whole. Yet linguists might certainly study similarities and differences in particular words or phrases across languages as that can be indicative of how various human languages evolved and could also be indicative of various aspects of culture. I could also mention that browsing through [Encyclopedia of Distance](https://catalog.lib.ncsu.edu/record/NCSU3718838 ) I read about how linguists have sought to create ways to measure distances between languages. 

Also, as a pratical application of such a cross-sectional approach within human languages, one might think of the airline and travel industry where employees learn how to say particular words and phrases in multiple languages so that it is possible to communicate with the passengers. 

So I think such comparisons could be interesting. 

I could mention that I don't think it's necessary to have a huge number of examples. I think a few would be fine with some brief explanation. I think perhaps more interesting than a lot of breadth would be how constraints, goals, or the problem domain lead to different approaches. I'm not an expert at all in any of those fields, so I may not be familiar with some of the terms. For people who find this page later on and are trying to find more details there can be a few resources listed such as books, websites, or search strategies. 

I've thought about how I might answer this question based on my independent study and what I looked into, so I could seek to work on my response tonight and probably tomorrow. As long as the question meets the site guidelines perhaps there could be then at least one response. Other responses though might be more comprehensive or more incisive and trenchant. So a better response would be more deserving of the credit from the asker and also reputation points. 

I was thinking of waiting a week or two before awarding an answer; however, if a response is made beforehand which I think is good I could just decide to award it to that one. 

There also might be a response before I post mine, and so if that one is good and I haven't finished mine I might not post mine at all. 

Hope this meets the site guidelines, but if not let me know. 
