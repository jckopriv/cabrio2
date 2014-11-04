#ifndef CABRIO_DATA_TYPES
#define CABRIO_DATA_TYPES


//Enumeration of image types, used to distinguish quads be association within a map.
enum class ImgType {NAME,
		    MANUFACTURER,
		    YEAR,
		    SCREEN,
		    MARQUEE,
		    VIDEO,
		    BACKGRND,
		    BOX2D,
		    BOX3D,
		    CART2D,
		    CART3D,
		    LOGO};
		    
		    
// not used yet, intended to eae switch on trabsition animations
enum class AnimType {FADEIN,
		    ZOOMIN,
		    ZOOMOUT,
		    FADEOUT};
		    
// switch on available layout types
enum class LayoutType {VLIST, 
		      HLIST, 
		      GRID};
		      
		    
		    
#endif