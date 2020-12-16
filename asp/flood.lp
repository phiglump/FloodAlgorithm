%flood.lp
%Author: Philippe Lumpkin
%Start Date: 3/23/2020
%Last Edit Date: 3/24/2020

%make sure that each edge contains defined nodes
:- not node(X), reachable(X).

% The first creates reachable nodes from the starting node
% The second continues to find the reachable nodes from all other reachable nodes
reachable(Y) :- edge(start, Y).
reachable(Y) :- edge(X, Y), reachable(X).

%show all of the reachable nodes only
#show reachable/1.
