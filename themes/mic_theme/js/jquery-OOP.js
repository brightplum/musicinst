/**
 * --------------------------------------------------------------------
 * jQuery-Plugin "jQuery OOP"
 * 
 * Version: 0.0.1, 12.08.2010
 * by Trevor Sheridan, trevorsheridan@mac.com
 *                      http://www.trevorsheridan.com/
 *
 * Copyright (c) 2010 Trevor Sheridan
 * Licensed under GPL (http://www.opensource.org/licenses/gpl-license.php)
 *
 * --------------------------------------------------------------------
 */

var Class = {
	
	make: function (context) {
		
		object = function() {
			
			//Pass the args onto the initializer and then go!
			var args = Array.prototype.slice.call(arguments);
			context.initialize.apply(this, args);
			
		};
		
		for (key in context) {
			if (key != 'initialize')
			object.prototype[key] = context[key];
		}
		
		return object;
		
	}
	
};