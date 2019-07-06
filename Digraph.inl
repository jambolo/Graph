/** @file *//********************************************************************************************************

                                                    Digraph.inl

						                    Copyright 2008, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Graph/Digraph.inl#3 $

	$NoKeywords: $

*********************************************************************************************************************/

#pragma once


/********************************************************************************************************************/

Digraph::Edge::Edge( Digraph::Node * pTo/* = NULL*/ )
	: m_pTo( pTo )
{
}
