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

I'd be curious though aside from data mining what resources or guidance for
distance function selection there would be for students and industrial
practitioners.

It's not that I'm faced with a particular distance function selection at this
moment; however, I'm just curious what resources there would be for me or
others if such a situation were to occur. 

It seems to me that distance function selection crops up in [data
clustering](https://en.wikipedia.org/wiki/Cluster_analysis) algorithms within
fields such as machine learning, computer vision, natural language processing,
speech recognition, etc.; however, it could also crop up outside of data
clustering. 

One way to answer would be to say that it can be easier to analyze with more
context. For a more specific problem there could be a variety of different
techniques that can be applied, and one can work empirically, but there is no
automatic best choice. This point is echoed in some of these
stat.stackexchange.com posts:

[Choosing a clustering
method](https://stats.stackexchange.com/questions/3713/choosing-a-clustering-method)

[Choice of distance metric when data is combination
text/numeric/categorical](https://stats.stackexchange.com/questions/68736/choice-of-distance-metric-when-data-is-combination-text-numeric-categorical/68756)

On the other hand, I think about things like the [central limit
theorem](https://en.wikipedia.org/wiki/Central_limit_theorem) or the
$n\log{}n$ lower bound for [comparison
sorting](https://en.wikipedia.org/wiki/Comparison_sort#Lower_bound_for_the_average_number_of_comparisons)
-- basically relationships that hold across the board. So I wonder how much
there could be general theorems like that which would apply to distance
function selection. 

A basic observation would be that
[L_1](https://en.wikipedia.org/wiki/Taxicab_geometry) can be computed with
less cost than [L_2](https://en.wikipedia.org/wiki/Euclidean_distance). Also
if one is just comparing
[L_p](https://en.wikipedia.org/wiki/Minkowski_distance) distances the
rooting step could be omitted as that doesn't change the comparisons. I would
think that from a Turing machine point of view L_{p-1} can be computed with
less cost than L_p though on an actual computer the number of cycles may be
the same. 

One way or another the distance function might not be the bottleneck and so
one could think about how [premature optimization may not make
sense](http://wiki.c2.com/?PrematureOptimization).

I could mention that I also took a brief look at [this Ph.D. thesis](http://ofirpele.droppages.com/ofirpele_phd_thesis.pdf) by [Ofir Pele](http://ofirpele.droppages.com/)
on distance functions, and so at the beginning it says:

>Our proposed methods have been successfully used both by com-
puter vision researchers and by researchers in other fields. The success of
the methods in other fields is probably because the noise characteristics in those
fields are similar to image noise characteristics.

which suggested to me that there could be some overlap in different cases; however, I haven't
read the research papers of the thesis in detail. 

Anyway, I'd be curious what people might say in terms of considerations for
students and practitioners when picking a distance function within an
algorithm or overall scheme. Within different fields a variety of different 
techniques and considerations may have accreted.
