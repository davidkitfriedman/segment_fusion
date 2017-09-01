Okay, so here are some of my thoughts along with some links to some of the things that I found interesting in my independent study. 

In multiple books I found sections speaking about clustering. In particular within these three books:

* *Introduction to Artificial Intelligence* by Mariusz Flasiński
* *An Introduction to Statistical Learning with Applications in R* by
Gareth James, Daniela Witten, Trevor Hastie, Robert Tibshirani
* *Data Mining: The Textbook* by Charu C. Aggarwal

there are sections speaking about hierarchical clustering.

For hierarchical clustering one can use an arbitrary dissimilarity measure and so they talk about that choice. 

It's not as though one dissimilarity measure predominates in artificial intelligence, another in statistical or machine learning, and then a third in data mining, but the dissimilarity measure is determined by the data, and what the data means in the context of the situation.

In the statistical learning book an example is given in the section on hierarchical clustering of how an online retailer might prefer a correlation based dissimilarity measure to the Euclidean distance. Clustering together shoppers who purchase less from shoppers who purchase more may not be as desirable as clustering together shoppers who purchase similar items.

In the data mining textbook an example is given of how the cosine measure can be used as a comparison between texts. That section speaks about how with a bag-of-words representation document length would be prominent. That wouldn't necessarily be desirable as similar documents on the same or similar subjects but with different lengths wouldn't get grouped together. 

In any event, as stated above, the dissimilarity measure is not determined by the field and nor is it being determined by the domain  (say medical, legal, business, etc.), but is being driven by the nature of the data and what that data means. 

In the case of hierarchical clustering then, if the algorithm is the same and the dissimilarity measures are being driven by the data (so they could certainly by the same across the three fields), then for that case these three fields are using distance functions in similar ways. 

To go out on a tangent, this raises a question in my mind concerning what are the distinctions between these three fields (and perhaps other fields). 

I thought it was interesting to read in the lead of the Wikipedia article on data mining that the title of a book was changed from *Practical machine learning* to *Data mining: Practical machine learning tools and techniques with Java* and the reason given was that it was largely for marketing purposes. 

And so the Wikipedia articles on machine learning and data mining both say that those terms are buzzwords. The end of the lead for the article on machine learning speaks about how projects may fail to work because the problems can be difficult. 

On that note I found it interesting in my independent study to read in the Wikipedia article on the [history of artificial intelligence](https://en.wikipedia.org/wiki/History_of_artificial_intelligence) how the [initial optimism](https://en.wikipedia.org/wiki/History_of_artificial_intelligence#The_optimism) and [few strings attached funding](https://en.wikipedia.org/wiki/History_of_artificial_intelligence#The_money) was then [met with disappointment](https://en.wikipedia.org/wiki/History_of_artificial_intelligence#The_first_AI_winter_1974.E2.80.931980) in the mid to late 1970's. So the article speaks about various failures (machine translation) and also successes (the DART battle management system).

In terms of distinctions between the three fields the Wikipedia article on machine learning states:

>Machine learning is sometimes conflated with data mining, where the latter subfield focuses more on exploratory data analysis and is known as unsupervised learning

Yet on the other hand in *Data Mining: The Textbook* the preface speaks of classification as being one of the four main super problems of data mining where it seems to me that classification as defined in chapter 10 of the book is basically supervised learning. 

In any event it suggests in my mind that the distinctions between these three fields might be a bit fuzzy, and the example above indicates that naming decisions could be driven by a variety of factors including marketing. 

Based on my independent study, to my ear, artificial intelligence being the first term coined, carries with it a connotation of a more theoretical field while machine learning and data mining are more focused on developing practical solutions. 

In the text on artificial intelligence chapter 17 includes a section called Determinants of AI Development where artificial intelligence is seen as drawing from such fields as: computer science, biology, neuroscience, physics, mathematics, logics, philosophy, linguistics, and psychology. 

There's a discussion of [Searle's Chinese room](https://en.wikipedia.org/wiki/Chinese_room), strong AI and weak AI, and a chapter on theories of intelligence in philosophy and psychology. There's a brief section on artificial intelligence as it pertains to social intelligence, emotional intelligence, and creativity. 

In Russell and Norvig's book *Artificial Intelligence: A Modern Approach* there is a chapter on philosophical foundations.

In comparison within *Data Mining: The Textbook* privacy is addressed but essentially as a technical problem. 

In [*Elements of Statistical Learning*](http://www.springer.com/us/book/9780387848570) (from which the above mentioned statistical learning book is based) the chapters look to be all of a technical nature. 

So I think this sentence from [History and relationships to other fields section](https://en.wikipedia.org/wiki/Machine_learning#History_and_relationships_to_other_fields) of the machine learning article is consistent with that assessment:

> The field changed its goal from achieving artificial intelligence to tackling solvable problems of a practical nature.

Thinking back to the article on the history of artificial intelligence one might wonder about how various funders of different kinds (government, corporate, philanthropic, etc.) began to see AI as a longer term prospect while machine learning and data mining were more likely to produce working results more quickly. 

I was curious about books in these three fields that were written from the perspective of a particular domain (medical, business, legal, etc.). So I did Google searches of the form: `textbook <field> <domain>` for field being either artificial intelligence, machine learning, or data mining, and domain being either medical, business, or legal. So a variety of different books have been written from the standpoint of a particular domain.

Data miners might be able to apply domain knowledge in the course of exploratory analysis, or in other kinds of analysis. 

---

So back to distance functions.

I see a difference in the way distance functions are used in hierarchical clustering within the fields artificial intelligence, machine learning, data mining and applications discussed in Ofir Pele's thesis within computer vision (which could be seen as a subfield of machine learning). Simply put various applications of the distance functions developed do not involve clustering. This is true for the multiple view geometry application mentioned at the beginning of the abstract for the thesis. 

In error-correcting codes the simple concept of Hamming distance is used; however in this case it seems to me that unlike the hierarchical clustering case no distance function choice is going on. Hamming distance arises from the mathematical model which in turn is from the physics of information transmission over noisy channels. 

In the case of a spell checker a simple implementation could just list words that are say 1 or 2 hops away under the edit distance; however, a more sophisticated approach can work better.

Spell checkers can take into account properties of language, keyboards, common errors, etc.

At another level of sophistication one could have spell checkers that seek to automatically learn characteristics of users so as to improve suggestions and other aspects of performance. 

In the case of a spell checker it doesn't seem to me that a distance function is necessarily warranted or helpful. 

If a mathematical concept doesn't seem useful for an application then one doesn't have to use it. 

---

I also wrote a summary of my independent study including listings of some of the various sources I went through:

[Summary of Independent Study](https://github.com/davidkitfriedman/segment_fusion/blob/master/summary_of_independent_study.md)

There is also an extended response which is available here:

[Extended response to distance function question on CS StackExchange](https://github.com/davidkitfriedman/segment_fusion/blob/master/cs_stackexchange_response_extended.md)

The length of the extended response ended up growing to a size of about 14 regular pages, so I can summarize what it is about:

In the extended response I continue the tangent in the middle which starts by comparing the fields of artificial intelligence, machine learning, and data mining. I speak about the question of whether research has shifted from universities to companies, the factor of motivation in education, economic systems and other systems for the organization of labor, social hierarchy, economic inequality, and climate change. 

To a certain extent I wonder if I did not entirely follow my own advice in terms of more breadth rather than depth; however, perhaps that's partly just the nature of the Internet.

I didn't do any portions of this for a class, but worked on it over the past few days. I brought in things that I had seen or read over the years.

I think that a lot of various other people have probably had similar thoughts and questions.

As distributed on GitHub this response is licensed under a [Creative Commons Attribution 4.0 International License](https://creativecommons.org/licenses/by/4.0/).
