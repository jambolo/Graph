/*****************************************************************************

                                   main.cpp

						Copyright 2001, John J. Bolton
	----------------------------------------------------------------------

	$Header: //depot/Libraries/Graph/Test/main.cpp#2 $

	$NoKeywords: $

*****************************************************************************/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Wx/Wx.h"

#include "..\Graph.h"
#include "..\Digraph.h"

static LRESULT CALLBACK WindowProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

static char	s_AppName[]		= "Graph";
static char	s_TitleBar[]	= "Graph";


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPreviousInst, LPSTR lpszCmdLine, int nCmdShow )
{
	Graph	graph( 1 );
	Digraph	digraph;

	if ( Wx::RegisterWindowClass(	CS_OWNDC,
									( WNDPROC )WindowProc,
									0,
									0,
									hInstance,
									NULL,
									LoadCursor( NULL, IDC_ARROW ),
									NULL,
									NULL,
									s_AppName ) == NULL )
	{
		MessageBox( NULL, "Wx::RegisterWindowClass() failed.", "Error", MB_OK );
		exit( 1 );
	}

	HWND hWnd = CreateWindowEx( 0,
								s_AppName,
								s_TitleBar,
								WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
								0, 0, 500, 500,
								NULL,
								NULL,
								hInstance,
								NULL );

	if ( hWnd == NULL )
	{
		MessageBox( NULL, "CreateWindowEx() failed.", "Error", MB_OK );
		exit( 1 );
	}

	int			rv;

	ShowWindow( hWnd, nCmdShow );

	rv = Wx::MessageLoop( hWnd );

	DestroyWindow( hWnd );

	return rv;
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

static LRESULT CALLBACK WindowProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{ 
	switch( uMsg )
	{
	case WM_CLOSE:
		PostQuitMessage( 0 );
		return 0;
	}

	return DefWindowProc( hWnd, uMsg, wParam, lParam ); 
} 


