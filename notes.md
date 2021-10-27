# Project.h

- Interessante keuze om drukknoppen in het Nederlands af te korten (DK) en de andere twee in het Engels...
- Ik ben op zich wel fan van defines, maar zou het ook niet handig zijn moest je die in een array krijgen? Zo kan je ze een stuk makkelijker "allemaal ineens als input zetten" of "allemaal nakijken" (in de mate dat dat nodig is). Nu moet je bij een extra knop niet alleen een extra define maken, maar ook heel je code nakijken om te zien of je overal de nieuwe knop hebt toegevoegd.

# App.cpp

- Heb ik het goed dat "addInput" de knop aan een uitgang toevoegt en "addAllOutInput" de alles uit is?
- De code in app.cpp ziet er heerlijk compact uit, met alle echte logica weggestopt. Als je dat kan volhouden komt het zeker goed.
- Wel wat verwarrend: het relais koppel je in App.h, maar de knoppen in App.cpp...

