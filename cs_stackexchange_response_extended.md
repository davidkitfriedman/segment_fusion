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

Thinking about the contrasts between artificial intelligence, machine learning and data mining one might conjecture about a rapid speeding up that has been going up over the past decades.

Say for example in the acceleration of the growth of companies going from IBM to Microsoft to Google to Facebook. Or say for example in the frequency of updates to software such as web browsers. One could also consider the rapid growth in use and availability of cryptocurrencies such as bitcoin. 

I think that accelerated growth can take a toll on employees: shorter deadlines, longer hours, more stress. One might think about stories [about Amazon](https://www.nytimes.com/2015/08/16/technology/inside-amazon-wrestling-big-ideas-in-a-bruising-workplace.html?mcubz=1) or [about Uber](https://www.google.com/search?safe=active&q=uber+corporate+culture+stress&oq=uber+corporate+culture+stress).

Going back to the history of AI has increased speed also influenced the thinking regarding funding decisions? According to Wikipedia in AI [few strings attached]( https://en.wikipedia.org/wiki/History_of_artificial_intelligence#The_optimism) was the policy of the early 1960's. Is it the case that today organizations whether government, corporate, or philanthropic, expect tangible practical results more quickly and with greater certainty? 

Faster growth and in particular greater volatility could make people more hesitant to fund longer term research because there can be uncertainty about whether the model upon which that research is based will persist or not. I remember reading about how oil extraction from Canadian oil sands only got to be profitable once petroleum prices reached a certain level ([Wikipedia article on the history of the petroleum industry in Canada](https://en.wikipedia.org/wiki/History_of_the_petroleum_industry_in_Canada_%28oil_sands_and_heavy_oil%29)). 

It's possible though that AI in the 1960's was somewhat of an anomaly and funding decisions of all sorts throughout history have generally been based on the expectation of a good possibility of tangible return. 

A few years ago I got involved in reading and following [GiveWell](http://www.givewell.org/). They are a small team of researchers that evaluates various charities. Just recently I revisited the site, and I have continued to donate to one of their top charities (Against Malaria Foundation). I think about their views in this context in the sense of return from investment in terms of speed, relative certainty, and measurability. Looking at their [priority programs](http://www.givewell.org/research/intervention-reports#Priorityprograms) one can see that they prioritize various medical interventions where it is possible to seek to measure after a period of time the level of success or failure. I was specifically thinking about their views on education. One gets the impression that for education they want to see that the education program leads to [good outcomes later in life and in particular income](http://www.givewell.org/international/education), and so they don't prioritize education so much because they take the view that they need good evidence that a particular program works, and that for education that is absent. Some of the views are talked about [here in 2007](http://blog.givewell.org/2007/07/30/my-favorite-cause/) and [here in 2009](http://blog.givewell.org/2009/05/08/where-i-stand-on-education/).

Aside from the question of what it means to say that a program works, (if students are learning one might think that the program is working irrespective of whether there are any employment figures) the tie-in in here with the earlier content on the history of AI is how perhaps in both cases there is a shift from the long-term to the short-term. 

A decrease in malaria might be noted after a distribution of bednets in a period of time, but educating a child that is five years old could be seen as a longer term matter. 

There's also the question of how much is progress being measured in terms of income and money. 

Thinking of education reminds me of some statistics that I read in [Tom Shadyac](https://en.wikipedia.org/wiki/Tom_Shadyac)'s book called *Life's Instruction Manual*. Shadyac speaks about data which indicate that most people who pursue higher education and go to school do so with the intention of gaining skills so as to function within the economy; with more skills it is possible to earn more money. Shadyac doesn't think it's a good thing but a bad one -- that it ends up being all about competition and greed.

On the other hand one might think about the aspect of motivation in learning. This was something that writer [Dale Carnegie](https://en.wikipedia.org/wiki/Dale_Carnegie) emphasized in his work *How to Win Friends and Influence People*. It's actually one of the first things he says. He also makes the same point at the beginning of *How to Stop Worrying and Start Living*.

Insofar as motivation is important to learning is it not money that provides that motivation? 

In the course of seeking to edit [this StackExchange question](https://cs.stackexchange.com/questions/80327/specific-examples-with-explanation-of-similarities-and-differences-of-how-distan) I happened to find [this page which has a list of data miners](https://www.import.io/post/38-great-resources-for-learning-data-mining-concepts-and-techniques/). I thought to myself: isn't it interesting that all of the data miners listed are at companies and none are in academia or government? When I actually went through the list though I realized that it's not exactly that simple. [DJ Patil](https://en.wikipedia.org/wiki/DJ_Patil) is listed there and he was working for the federal government of the United States for a brief time, and [Andrew Ng](https://en.wikipedia.org/wiki/Andrew_Ng) teaches at Stanford (I found [Jeff Hammerbacher](https://en.wikipedia.org/wiki/Jeff_Hammerbacher)'s page linked from DJ Patil's). That doesn't mean that they haven't worked for private companies also. Most are working for companies. But it's also worth keeping in mind that this is just one list that I found through Google searching, and so many of the people on the list are journalists, consultants, published authors, etc. All the links are to twitter feeds. So in these lines of work people seek to get attention from people: consultants advertise for customers, publishers promote authors, etc. I would think that there are a lot of intelligent people throughout different sectors (academia, corporate, government) who don't maintain a twitter feed or run a mailing list insofar as they don't have as much of an incentive to do so. (One might note in passing that they are all men). 

Nevertheless, thinking about the history of artificial intelligence article, one might ask whether the frame of the historical camera is more filled with universities than companies for the 1960's. The article specifically mentions MIT, Stanford, CMU, and Edinburgh University as main centers of AI research. Some of the most prominent people such as Marvin Minsky and John McCarthy were at universities. 

One might wonder about how in fifty years from now encyclopedia articles on the history of artificial intelligence, or machine learning, or data mining will look. Maybe there is a shift going on right now in that companies occupy a more prominent role in research. The articles fifty years from now might so to speak have more weight on companies. 

There's a phrase that I picked up from reading economist [Alan Greenspan](https://en.wikipedia.org/wiki/Alan_Greenspan)'s book *The Age of Turbulence*: how people can organize themselves to create value. Greenspan was specifically speaking about capitalism and communism; however, I think it could really be applied to all kinds of systems: Wikipedia, StackExchange, [free software](http://www.gnu.org), food co-ops, corporations, etc. 

Greenspan believes corporations should not be unduly regulated in their business operations which produce value for customers, shareholders, and employees. People today might have latent animosity and suspicion of big companies, but of course corporations produce all sorts of things: software, hardware, cars, airplanes, etc. Corporate cultures vary from place to place and corporations are involved in all sorts of philanthropic work. There would be examples of corporations taking note of the social effects of their actions. 

But one might wonder about how much graduates are drawn to the commercial sector.

In preparing this response I chanced upon the Wikipedia page for Jeffrey Hammerbacher who said:

>The best minds of my generation are thinking about how to make people click ads. That sucks.

I wonder if Albert Einstein was born in 1979 instead of 1879 would he have been working at Google instead of Princeton? Would that have been better? Reading Walter Isaacson's book one gets the sense that Einstein spent years of his life pursuing a [unified field theory](https://en.wikipedia.org/wiki/Unified_field_theory) that many considered most likely fruitless. My recollection is that Isaacson used the word "crackpot" in referring to Einstein's views on world government and control of nuclear arms. 

At a company would somebody be reassigned or would fail to get funding if a project seemed unlikely to work or which didn't seem to have a purpose? 

In this sense are corporations or perhaps universities that might act more like corporations the wave of the future? It goes back to this question of how people organize themselves to create value. To what extent can money help to get everybody on the same page?

On the other hand, how much are companies distinct from universities in that their essential goal is to sell something? Or as in the case for Internet companies they are in the business of helping somebody else to sell something.

On the one hand companies might feel projects seen as long-term, theoretical, experimental, or speculative could be a waste of time and money. On the other hand, in the modern funding environment, companies might be the only places such research gets done. Companies are flush with cash so a corporation might be willing to allocate sums as long as they feel they could learn something. At least in the US one finds deficits rising, budgets cut, and Republicans and fiscal conservatives hold political power. Many Republican legislators and office holders may feel that it is better for companies to work on problems than it is to allocate public money. 

I found it interesting to read [this piece published by the American Historical Association by Robert B. Townsend](https://www.historians.org/publications-and-directories/perspectives-on-history/september-2007/google-books-is-it-good-for-history). Townsend speaks about various problems with Google Books,   including content errors, metadata errors, and public domain truncation. The piece is from September of 2007 but my sense is that these same issues are still extant as mentioned on the [Wikipedia page for Google Books](https://en.wikipedia.org/wiki/Google_Books). A [*New York Times article* from 2015](https://www.nytimes.com/2015/10/29/arts/international/google-books-a-complex-and-controversial-experiment.html) that I found through Wikipedia speaks about different problems. Townsend spoke about the matter of how books in the public domain (say for example because they are published by the US federal government) but published on or after January 1, 1923 are still restricted. I've encountered that directly and so have begun a project to scan *The Eagle and the Shield* a book about the history of the Great Seal of the United States and published in the mid 1970's. 

Townsend writes:

>So I have to ask, what's the rush? In Google's case the answer seems clear enough. Like any large corporation with a lot of excess cash the company seems bent on scooping up as much market share as possible, driving competition off the board, and increasing the number of people seeing (and clicking on) its highly lucrative ads or "renting" copies of the books. But I am not sure why the rest of us should share the company's sense of haste. 

Is that unfair to Google? 

In [2009 Sergey Brin wrote an editorial in the *New York Times* about Google Books](http://www.nytimes.com/2009/10/09/opinion/09brin.html) speaking about among other things the possibility that books might be lost because of disasters such as fires or floods, and also that there is significant information available in books that can be helpful to people. 

Google may have felt that authors and publishers wouldn't object to their scanning because they were creating another way for them to gain sales; that it was essentially win-win. 

Also, how is the automated scanning, indexing and searching of copyright print books any different from the automated crawling, indexing and searching of copyrighted web sites? Logically speaking should the medium really make that much of a difference? In both cases the default being inclusion though owners have the ability to opt-out (say in the case of the web via [robots.txt](https://en.wikipedia.org/wiki/Robots_exclusion_standard)). 

This [*Wired* article](https://www.wired.com/2017/04/how-google-book-search-got-lost/) indicates that the project has decreased in size and that the scanning of books has slowed. 

In any event, it raises the question in my mind if corporations may be stimulated, encouraged, or compelled to do certain things in certain ways. 

Google may have felt that they needed to scan the books quickly because otherwise another company might do so (say for example Microsoft). 

I don't know whether the [Internet Archive](http://www.archive.org/) has higher quality metadata in their database. Just using it casually I've periodically noticed things that looked to be errors of some kind. 

Has evidence been put forth that other databases say at the United States Library of Congress have better metadata?

That might be the case insofar as the Library of Congress wasn't necessarily subject to as much force pushing it to move as quickly as Google. Plus their systems evolved over a period of time in which people didn't feel a need to move as fast. 

Motivation can be a big factor in education but also a major factor in the actions of companies. Why did company X take action Y? What were the forces that led to that? What was some of the thinking behind it? In particular, in the case of research, corporate research can end up being utilized for corporate profit. 

I wonder about whether if early research in computer networking has been funded more by companies and less by government the current situation today would be more monetized and more balkanized; competing protocols, glue technology, and additional fees for packets going from one network to another. Bills for Internet service would vary month to month depending on the destination of the packets. 

I've sometimes wondered about how there are multiple web browsers that have a large overlap in their functionality with the resulting duplication of labor, additional cases for web programmers and possible added hassle for users. Such duplication is a natural consequence of capitalism and competition. It's a topic that was touched on by [Sheena Iyengar in a TED talk from 2010](https://www.youtube.com/watch?v=lDq9-QxvsNU&feature=youtu.be&t=520). On the other hand having used both Firefox and Chrome I wonder to what extent a company like Google can move faster in terms of adding features, testing web sites, improving speed -- all benefits to users. Competition between companies can end up being a benefit to customers.  

I've continued to use Firefox because I like the way that the browsing history if set up; however, I'll often switch to Chrome for particular sites. 

Would it have been better if just one web browser had gotten to be a de facto standard? I don't know how exactly that could have played out, but I think about various Internet protocols and so somehow it was possible for agreements to be made, or at least practices to stabilize. I also briefly investigated mail servers and DNS servers. For mail servers the [data I found](http://www.securityspace.com/s_survey/data/man.201707/mxsurvey.html) (site seems to be having some problem with constant refreshes; but I could read it by using stop) linked to from a [Wikipedia article listing mail server software](https://en.wikipedia.org/wiki/List_of_mail_server_software) suggest that the two main ones are Exim and Postfix, while in the case of DNS servers  [BIND is the de facto standard](https://en.wikipedia.org/wiki/BIND) and seems to be [widely used](http://dns.measurement-factory.com/surveys/201010/). That Wikipedia article on mail servers mentions that such studies can be difficult to carry out. The [dominance of Microsoft Windows on PCs for general consumers](https://www.netmarketshare.com/operating-system-market-share.aspx?qprid=10&qpcustomd=0) would be another example of a sort of standardization (not so though to as great an extent within CS or among scientists, engineers, and mathematicians). 

It would seem authoritarian for a government to mandate the exclusive use of one government developed web browser. Ed Snowden's disclosures also indicate that the US government has sought to put in backdoors, so there would also be privacy issues. Such a thought reminds me of the age of prohibition in the United States insofar as people sought to find ways to get around it. 

Though capitalism does have this property of replication in the course of competition the record of the twentieth century shows that in communist countries there could be more severe issues. I would imagine though that within scholarship there has been a fair amount of thinking and analysis of how much problems in communist countries had to with the economic system, and how much it had to do with other things such as corruption and authoritarian political rule. One thought is whether a communist economic system tends to lead inevitably to authoritarian political rule.  

Having done some investment research I get the sense that various companies with the highest market capitalization are those that essentially deal in intellectual work; among them companies in IT, finance, and pharmaceuticals. In the case of IT, pharmaceuticals, and to a certain extent finance the businesses rely on government legal protections for the fruits of intellectual labor. By intellectual labor I would include marketing and branding which could be seen as creative endeavor that can be tested, analyzed, and measured with scientific and technical means. Google is seen as the maker of Chromebooks but I imagine generally speaking the actual manufacturing of consumer electronics is not as profitable as other kinds of business, and in the case of Chromebooks is handled by other companies. Pharmaceutical companies do need to manufacture drugs; however, that may be a small part of the cost wherein research and development in addition to advertising can be more. Finance companies may not have intellectual property in the form of something like software, but they have brands that they would seek to protect and there are laws to support that. For finance companies the intellectual work can consist among other things of modeling and analysis for the purpose of loans, investment, etc. 

It's true that companies such as Google and Facebook have intellectual property in the form of patents and copyright; however,  a lot of the business value has to do with what might be termed market penetration. People use the sites, and have it bookmarked on their computers and also in their minds. Advertisers can seek to get human attention for their offerings. This aspect isn't really protected via legal means such as copyright and patents. Consumers could stop using any using particular site for any number of reasons. 

In what ways and to what extent is the business world different from the days of Cornelius Vanderbilt, Andrew Carnegie, and John D. Rockefeller? These people created businesses based on railroads, steel, and oil. (I found it interesting to read the [Autobiography of Andrew Carnegie](http://www.gutenberg.org/ebooks/17976) a number of years ago. Carnegie spoke about the interdependence of capital, labor, and employer (Chapter XVII: The Homestead Strike)). 

In both the industrial age, and the information age successful businesses have carried out organization, planning, and analysis; however, I wonder if today intellectual property and marketing play more significant roles at least for the biggest businesses today as measured by market cap. 

Pfizer was founded in 1849. Fifty-four years after the birth of Vanderbilt but only fourteen years after the birth of Andrew Carnegie and ten after the birth of John D. Rockefeller. I wonder to what extent in the 19th century pharmaceutical companies relied not so much on legal protections as on trade secrets. They just didn't tell anybody how they did it. Customers and competitors didn't necessarily have the knowledge or technology to replicate it. 

I remember reading about how Benjamin Franklin refrained from seeking patents on various inventions he developed so as to provide them for general use by the public. On the other hand one might wonder in Franklin's day to what extent was it possible for inventors to prevent people from copying their designs.

Or in the case of creative work Edgar Allen Poe's poem "The Raven" was quite popular [but Poe made little money from it](https://en.wikipedia.org/wiki/The_Raven). I don't know if that is because publishers did not respect his copyright and pay him royalties or if it was simply the case that the deals that got arranged were not favorable to him financially. 

In any event one might wonder whether expectations for the reward of intellectual achievement were different in 19th century America than they are today. 

To what extent does modern technology and modern infrastructure create a system where innovation and competition in innovation is financially motivated along with expectations about the just and deserved rewards for intellectual achievement? 

The modern education system is designed to prepare people to be members of the modern economic system which maps onto and is correlated with the social hierarchy. 

In *The Spirit Level* by Richard Wilkinson and Kate Pickett data is presented which suggests that social problems such as obesity, mental illness and crime are associated with economic inequality within the social hierarchy. In countries such as the US and the UK where economic inequality are greater those problems are worse. In various Scandinavian countries where economic inequality is lower such problems are less. These are [some slides](https://www.equalitytrust.org.uk/resources/the-spirit-level) publicly available that summarize their findings. I haven't studied criticism of their results; however, I did see some linked to from the [Wikipedia article on the book](https://en.wikipedia.org/wiki/The_Spirit_Level:_Why_More_Equal_Societies_Almost_Always_Do_Better#Critical_response).

I did however investigate other things such as [happiness](https://en.wikipedia.org/wiki/World_Happiness_Report), [press freedom](https://en.wikipedia.org/wiki/Press_Freedom_Index), [democracy](https://en.wikipedia.org/wiki/Democracy_Index), [charitable giving](https://en.wikipedia.org/wiki/World_Giving_Index), [corruption](https://en.wikipedia.org/wiki/Corruption_Perceptions_Index) and [suicide](https://en.wikipedia.org/wiki/List_of_countries_by_suicide_rate). Just casually doing some various Internet searches I tended to find the same relationship with inequality for happiness, press freedom, corruption and democracy, but not so for charitable giving or suicide. I didn't do a specific statistical analysis but just took a look at the results. 

In the book they address suicide speaking about how in more equal societies people may tend to blame themselves to a greater degree for problems while in less equal societies people can be more likely to project anger outward (beginning of chapter 13, Dysfunctional Societies). 

They also speak about how in nations with lower economic inequality allocations of foreign aid to help developing countries are higher than in nations with greater levels of economic inequality (chapter 4, Community life and social relations, Trust Beyond Borders). 

I wonder also if in countries with greater inequality social problems are more prevalent and more visible stimulating people to give. For example seeing the homeless on the street people want to try to help the situation. 

I think that biologists could speak about social hierarchies in various animals such as dogs, elephants, orcas, and primates. This suggests to me that mental processes and infrastructure related to societal hierarchy can be deeply embedded in human minds. One can find some sort of ranking and division of labor in all sorts of civilizations and cultures. 

On the other hand that observation by itself doesn't imply that greater economic equality would lead to fewer social problems. I have no reason to believe that among various animal species more aggressive behavior is found where there is more inequality and less aggressive behavior is found with greater equality. 

Another point is that social ills can be correlated together and measures of social well-being can be correlated together. Where there is greater obesity one would expect to find more heart attacks and more diabetes; however, that doesn't automatically imply that economic inequality tends to cause obesity. 

So I would regard the conclusion that inequality causes social problems as a working scientific hypothesis that can guide policy. Further investigation, data, and evidence could corroborate it or cast doubt on it. Like any scientific hypothesis it could be incomplete or wrong. 

Although in the past ten years in the United States the [GINI index](http://data.worldbank.org/indicator/SI.POV.GINI) has not increased as much as it did in the early 90's my sense is that things have gotten better for investors and consumers but for employees and students not as much. Investors see a growing stock market and consumers can get things like cell phones with more features and better performance at lower costs. Employees however see stagnant wages and salaries while students face increasing tuition costs. 

The US and the UK are more racially and ethnically heterogeneous than the Scandinavian countries and that can influence the interactions and dynamics within a nation. I wonder if the path to a social welfare state like that in the Scandinavian countries could be similar for the US and the UK but might just take longer. Just like one or another student might learn something very quickly while for the rest of the class it could take longer. 

I've been informally practicing stenography for about a year and a half now and although some people got to professional speeds of over 200 WPM in about a year such as [Mirabi Knight](http://stenoknight.com/StenoSchool.html) and [Stan Sakai](http://plover.stenoknight.com/2015/12/introducing-aloft-from-stan-sakai-and.html). I haven't been able to improve that quickly. My testing indicates that after about a year and a half my steno is still a bit below my QWERTY which is perhaps about 70 - 80 WPM; however, with more practice and other various changes I can seek to gain more speed. One might note that Mirabi Knight was going into stenography with a QWERTY speed of [110 WPM](http://stenoknight.com/bio.html) far above the average.

In chapter 15 of *The Spirit Level* Wilkinson and Pickett tie economic inequality to consumerism and climate change. 

Drawing upon the work of economist [Tim Jackson](https://www.ted.com/talks/tim_jackson_s_economic_reality_check) one might contrast:

>how people can organize themselves to create value

with

>how people can organize themselves to create prosperity 

Prosperity taking into account material human needs in addition to other human needs as one finds within biology throughout different species. 

In terms of curbing and regulating businesses that might decrease economic inequality and lead to greater prosperity or it might not. To model the relationship between students, consumers, businesses and employees, etc. as a [zero sum game](https://en.wikipedia.org/wiki/Zero-sum_game) may not be accurate. One can try to figure out what's going on. Lots of decisions needs to be made with uncertainty. 

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


This extended response is licensed under a [Creative Commons Attribution 4.0 International License](https://creativecommons.org/licenses/by/4.0/).
