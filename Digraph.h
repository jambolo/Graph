/** @file *//********************************************************************************************************

                                                     Digraph.h

						                    Copyright 2008, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Graph/Digraph.h#3 $

	$NoKeywords: $

*********************************************************************************************************************/

#pragma once

#include <vector>


/********************************************************************************************************************/

class Digraph
{
public:

	class Node;
	class Edge;

	typedef std::vector<Node *>	NodeList;
	typedef std::vector<Edge *>	EdgeList;

	NodeList	m_Nodes;
};


/********************************************************************************************************************/

class Digraph::Node
{
public:

	Digraph::EdgeList	m_Edges;
};


/********************************************************************************************************************/

class Digraph::Edge
{
public:

	Edge( Digraph::Node * pTo = NULL );

	Digraph::Node *	m_pTo;
};

/********************************************************************************************************************/

#include "Digraph.inl"
