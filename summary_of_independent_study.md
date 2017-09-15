In this file I talk about some of the things I did in my independent study. 

(Note: I have some math included in the text (enclosed in `$`'s) and so this doesn't show up properly in GitHub; however, one could use StackExchange - Ask a Question or also [StackEdit](https://stackedit.io) to view it)

I wrote down various books that occurred to mind from my days as a student that I thought might possibly cover distance functions or mention them. 

Here are some of the books that I wrote down:

* *Algorithms* (Cormen, Leiserson, Rivest, Stein)
* *Concrete Mathematics* (Graham, Knuth, Patashnik)
* *The Art of Computer Programming* (Knuth)
* *Computational Complexity* (Papadimitriou)
* *Introduction to the Theory of Computation* (Sipser)


Then I did various Google searches such as for "university", "statistics department", "computer science department", etc. I actually thought that perhaps Stanford would be returned as the top listing for the query "university" as was true when I tried that in the late 90's/early 2000's; however, as Google now takes into account location information NC State was returned at the top of the  list; NC State being the closest large university to my location in Raleigh, North Carolina. 

I went through course descriptions for the statistics, computer science, and math departments, and so sought to find additional courses and books that might speak about distance functions.

I also did various other queries and search strategies.

Some of the books or resources I actually had heard of in other ways. I simply saw *Taxicab Geometry* among my dad's technical books, and I knew about Alexander Bogomolny's site Cut The Knot from back in the late 90's early 2000's. 

Before doing the independent study though I didn't know whether Bogomolny would have content on distance functions, but I certainly thought he might. Anyway, I went through some of Bogomolny pages and sought to answer question and do proofs before looking at the further exposition and explanation.

[Cut The Knot: Objects distant and near](https://www.cut-the-knot.org/do_you_know/far_near.shtml)

I think I actually spent some of the most time with those two sources (*Taxicab Geometry* and Cut The Knot). *Taxicab Geometry* was interesting. It's a small book and there's not much exposition, but it has various questions and then there are selected answers in the back. I picked some random questions from chapter 1 and sought to do them on the bus and they didn't take too much time so I wondered if the book might be too elementary. 

When I got to chapter 2 the questions seemed to me more difficult. I wondered if the expectation for some of the parts was just simply to find a particular example of a point satisfying particular criteria, and not a mathematical description of the full set of points. Nevertheless I sought to find the whole set and interpreted the questions that way.

When I looked at the back of the book I was a bit surprised to see that not only was the answer speaking about the whole mathematical set but it was actually more general than my approach. The answer spoke about the continuous case and I had only considered the integer. For example if the question asked for points C such that the distance from A to C plus the distance from B to C is equal to 10 I found points that were 0 and 10, 9 and 1, 8 and 2, etc. The book's solution included all of them not just the integer (for example 0.33 and 9.67, 1.2 and 8.8). 

It wasn't difficult though for me to extend my approach to cover the continuous case.

It also seems to me that an easier question was interspersed among more difficult ones. That's something that Knuth spoke about in *Art of Computer Programming*. He didn't think it was necessarily good to put unsolved research questions amid basic exercises without any information about the difficulty. And so there is a rating system for the difficulty of questions in *Art of Computer Programming*. 

People might wonder about that. An argument against giving a rating is that in real life people aren't going to give the student a rating of how difficult the problem is. A counter-argument is that that might not necessarily be true in a work place situation. A supervisor might give an employee a sense of how long they expect something to take and how difficult it is. Another thought on it though is whether math problems done in school are real or not. The students are real people using real numbers doing real calculations. It reminds me of a Martin Gardner column and so Gardner was speaking about [mathematical realism](https://en.wikipedia.org/wiki/Philosophy_of_mathematics#Mathematical_realism); that mathematical objects are not just the creation of human minds but that they exist as real things, albeit not in some exact physical location such as orbiting Jupiter, but nevertheless altogether real. (I believe Gardner used the word "platonism" in the column). 

Another argument though against giving a rating is that such a policy helps students to be independent in assessing problems, relationships and concepts on their own. Teachers might seek to challenge students in that way. 

*Taxicab Geometry* can encourage people to experiment on their own. 

And so I thought of a mathematical question on my own while going through the text in the course of working on the problems.

Within mathematics it's possible to write simple statements such as:

1. There exists no positive integers $a$, $b$, and $c$, such that $a^4 + b^4 = c^4$.

1. If $n+1$ distinct integers are selected between $1$ and $2n$ inclusive then there must exist two integers that are relatively prime. 

1. Any even integer greater than or equal to $4$ can be written as the sum of two primes. 

1. There exists no positive integers $a$, $b$, and $c$, such that $a^3 + b^3 = c^3$. 

1. There exists no positive integers $a$, $b$, and $c$, such that $a^n + b^n = c^n$.

Many high school students studying math would be able to understand what these statements say. 

The difficulty of understanding each statement is essentially the same. Yet, subject to human inquiry, the amount of energy required to prove them is vastly different.

$1$, $4$, and $5$ are talked about in the Wikipedia article on [Fermat's Last Theorem](https://en.wikipedia.org/wiki/Fermat%27s_Last_Theorem#Proofs_for_specific_exponents). $2$ is a problem that I saw in a book about [Paul Erdős](https://en.wikipedia.org/wiki/Paul_Erd%C5%91s) called *My Brain is Open*, and $3$ is the unproven [Goldbach's Conjecture](https://en.wikipedia.org/wiki/Goldbach%27s_conjecture). 

The simplicity of a mathematical statement then does not necessarily say anything about the difficulty of its proof. 

The same is true of combinatorial statements. The number of possible results when a coin is flipped 100 times is simpler than the number of possible successions of wins and losses in a 7 game series. 

On the other hand, a high school student studying calculus, could be able to do the integral $3x^2 + x^4$ as well as the integral $3x^2 + x\sin{x}$. Students who are able to do both would realize that more tools are being used and more steps are required in the latter than in the former. 

Young children who are studying arithmetic would know that is takes longer and requires more steps to multiply four digit positive integers than it does to multiply two digit positive integers. 

Ascertaining the difficulty then of a problem could be seen as a skill in and of itself aside from the actual computation, answer and result. 

In *The Man Who Lived Only Numbers* by Paul Hoffman an incident is related in which a mathematician by the name of [Michael Jacobson](https://en.wikipedia.org/wiki/Michael_Scott_Jacobson) asked Paul Erdős about a particular problem and Erdős said he should find something else to work on; that it was too difficult. In the book Johnson speaks about how Erdős's advice was altogether right insofar as years later the problem had still not been solved. 

Although [Gauss](https://en.wikipedia.org/wiki/Carl_Friedrich_Gauss) was encouraged by his friend astronomer Heinrich Olbers to pursue Fermat's Last Theorem wherein a prize was offered by the French Academy of Sciences he declined to do so writing:

>I confess that Fermat's Theorem as an isolated proposition has very little interest for me, because I could easily lay down a multitude of such propositions, which one could neither prove nor dispose of.

([As quoted in Wikiquote from *The World of Mathematics* (1956) Edited by J. R. Newman](https://en.wikiquote.org/wiki/Carl_Friedrich_Gauss))

See also: 

[NOVA - Math's Hidden Woman](http://www.pbs.org/wgbh/nova/physics/sophie-germain.html)

It does appear though that Gauss pursued Fermat's Last Theorem as described by Leo Corry in the below listed reference: 

[On the History of Fermat’s Last Theorem: A Down-to-Earth Approach by Leo Corry - Tel Aviv University - DRAFT NOV. 2007 - NOT FOR QUOTATION](http://www.tau.ac.il/~corry/publications/articles/pdf/Fermat-History.pdf)

(page 13, section 4. FLT between 1800 and 1855 – still in the margin,"Gauss indeed gave some thought to the problem:")

So those two examples could be seen as cases where a mathematician either instinctively, or perhaps after a period of time, intuitively, gauged the difficulty of a problem. 

A toddler that doesn't know the meaning of letters of digits wouldn't know that it is more complicated to multiply together four digit numbers than two digit numbers, and a young child doing multiplication does not know that integrating $3x^2 + x\sin{x}$  requires more knowledge of calculus than integrating $3x^2 + x^4$. Over time however one can progress in the accumulation of knowledge so as to be able to know such things. 

Simple mathematical statements may have simple proofs or nothing of the kind may appear to exist. 

So I went through *Art of Computer Programming* a bit and reviewed a section that was about minimizing the number of logic gates to achieve some particular truth table. I believe it was functions of the form where the output is true when k of the boolean variables are true. And so I think there was a reference to a kind of distance
 in that part.

I thought it was interesting in the Preface to read a comment from Knuth on the patenting of algorithms. He discouraged people from doing so. When reading the [legal section of the VideoLan.org page](https://www.videolan.org/legal.html) I saw it says that software patents are not recognized in France nor recognized within European conventions; however, looking at it more closely it seems that there are some various European software patents. These are some of the sources I visited:

* [Wikipedia page on Software patents under the European Patent Convention](https://en.wikipedia.org/wiki/Software_patents_under_the_European_Patent_Convention)

* [Free Software Foundation: Saving Europe from Software Patents](https://www.gnu.org/philosophy/savingeurope.en.html)

* [Software patent debate](https://en.wikipedia.org/wiki/Software_patent_debate)

* [Foundation for a Free Information Infrastructure: Frequently Asked Questions about software patents](https://www.ffii.org/Frequently%20Asked%20Questions%20about%20software%20patents) - It says, "About 30,000 European software patents have been granted without a sufficient legal base." And so I also read what it says about trivial patents. 

Another comment is that I was rather surprised at how many books in the mathematical field of analysis can be downloaded at no cost and without a university affiliation. I found a list at the [Online Books Page](http://onlinebooks.library.upenn.edu/)

[Mathematical analysis -- Textbooks at Online Books Page](http://onlinebooks.library.upenn.edu/webbin/book/browse?type=lcsubc&key=Mathematical%20analysis%20--%20Textbooks)

And so this is one of the books that I downloaded:

* [*Real Analysis* by Brian S. Thomson, Judith B. Bruckner, Andrew M. Bruckner](http://classicalrealanalysis.info/index.php)

There were also a variety of other textbooks that were available at no cost and without a university affiliation in different fields:

* [*Computational Complexity: A Modern Approach* by Sanjeev Arora and Boaz Barak](http://theory.cs.princeton.edu/complexity/)
* [*Foundations of Data Science* by Avrim Blum, John Hopcroft and Ravindran Kannan](https://www.cs.cornell.edu/jeh/book2016June9.pdf)
* [*Probability Theory and Stochastic Processes with Applications* by Oliver Knill](http://www.math.harvard.edu/~knill/books/)
* [*A Programmer's Guide to Data Mining* by Ron Zacharski](http://guidetodatamining.com/) -- If you have seen the Head First books this one is a lot like that. 
* [*Mining of Massive Datasets* by Jure Leskovec, Anand Rajaraman, Jeffrey D. Ullman](http://www.mmds.org/)
* [*Artificial Intelligence: Foundations of Computational Agents* by  David Poole and Alan Mackworth](http://artint.info/)

For most of these I just briefly went through looking and reading over various parts that referred to distance.

I wondered if part of the reason that a wide variety of math analysis books are available at no cost to anybody with an Internet connection just has to do with the differences in how much money is involved in one field or another.

The libraries I used were D.H. Hill and Hunt at NC State, and Carylyle Campbell Library at Meredith College. 

I was surprised that at N.C. State at the D. H. Hill Library I could use the computers at no cost and was able to download PDF files of various books without any specific DRM. I thought I might be able to look at the books but not be able to download and keep them. Here are some of the books that I was able to download:

* *Computer Vision: Algorithms and Applications* by Richard Szeliski
* *Data Mining: The Textbook* by Charu C. Aggarwal
* *Introduction to Artificial Intelligence* by Mariusz Flasiński
* *Issues and Challenges in Artificial Intelligence* Zdzisław S. Hippe, Juliusz L. Kulikowski, Teresa Mroczek, Jerzy Wtorek Editors
* *Distance Geometry: Theory, Methods, and Applications* by Antonio Mucherino, Carlile Lavor, Leo Liberti, Nelson Maculan (Editors)
* *Encyclopedia of Distances* by Michel Marie Deza, Elena Deza
* *An Introduction to Statistical Learning with Applications in R* by Gareth James, Daniela Witten, Trevor Hastie, Robert Tibshirani 

It seems that the ones I could download were those published by Springer-Verlag. They also seemed to be available at fairly low cost (say \$30 or so) via Google Books. 

I downloaded these from the Internet, and I thought they were legitimate copies; however, now I think that they are most likely not:

* *Principles Of Mathematical Analysis* by Walter Rudin
* *Real and Complex Analysis* by Walter Rudin

And so I deleted the PDFs from my computer. 

Nevertheless it was interesting to go through them a bit, and I also took a look at this review of "baby Rudin" on the MAA site and how it arouses strong passions:

[Review of Principles of Mathematical Analysis by Walter Rudin posted on the MAA site](https://www.maa.org/press/maa-reviews/principles-of-mathematical-analysis)

One can join Friends of NC State Library for a fee of I believe about \$150 (\$175 as of October 2017) and one can join friends of Carlyle Campbell Library for a fee of \$25. Discounts are available at Meredith College for students at another university. 

When my parents visited they treated me to membership in the Friends of Carlyle Cambell Library in the course of the project to scan *The Eagle and the Shield* (a book about the history of the Great Seal of the United States published in the mid 1970's which is in the public domain but unscanned); however, I didn't join Friends of NC State Library as I didn't think it was necessary. 

With the Carlyle Campbell Friends membership I was able to check out  *Taxicab Geometry* and also *Concrete Mathematics* by Knuth, Graham, and Patashnik. 

Other than that I downloaded Ofir Pele's PhD thesis:

[Ofir Pele's Home Page](http://ofirpele.droppages.com/)

And also a paper speaking about categorization of different kinds of clustering algorithms that is referenced in the [Wikipedia article on cluster analysis](https://en.wikipedia.org/wiki/Cluster_analysis).

Estivill-Castro, Vladimir (20 June 2002). "Why so many clustering algorithms — A Position Paper". ACM SIGKDD Explorations Newsletter. 4 (1): 65–75 doi:[10.1145/568574.56857](https://doi.org/10.1145%2F568574.568575)

I used the computers at NC State to get that article. 

There were also two books by Sedgewick that I took a brief look at:

* *Alogrithms* (Sedgewick)

* *An Introduction to the Analysis of Algorithms* (Sedgewick)

In both of these cases I could just look at the book while at the library, and so there were some parts that spoke about different distance functions. 

I had written down *Artificial Intelligence: A Modern Approach* by Russell and Norvig (when I did a Google search for "artificial intelligence textbook" that was at the top); however, that book was not as easy to obtain. I didn't seek to make an extra effort just to look at it briefly, and I figured that I had Flasiński and also Poole and Mackworth. I also suspected that in Russell and Norvig distance functions didn't necessarily crop up that much. 

I was nevertheless able to see the table of contents on the website. 
