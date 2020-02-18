#pragma once

/*
	A Listener class used by guiitems for event generation
*/
class Listener
{
	public:
		virtual bool MouseMove ( int x, int y ) = 0;
		virtual bool MouseLBDown ( int x, int y ) = 0;
		virtual bool MouseLBUp ( int x, int y ) = 0;
};
