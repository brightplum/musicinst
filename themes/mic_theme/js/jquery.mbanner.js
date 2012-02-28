(function($) {

//Prototype style classes, with jQuery flair!
var mBanner = Class.make({
	
	initialize: function(_element, _content, _speed) {
		
		this._element = _element;
		this._content = _content;
		this._speed = _speed;
		
		this.images = Array();
		this.loadCount = 0;
		
		this.busy = false;
		
		//Setup the initial messenger
		this.loading = new this.loading($(this._element.selector +' .loading'), {});
		this.loading.setMessage('Loading '+ this.loadCount +' of '+ this._content.length);
		this.loading.show();
		
		//Loop through each image and then load!
		for (i = 0; i < this._content.length; i++)
			this.load(this._content[i].image);
		
	},
	
	startEngine: function() {
		
		ctx = this;
		
		//Add all of the images to the DOM
		$(this._element.selector +' .images').hide();
		
		for (i = 0; i < this.images.length; i++) {
			
			container = document.createElement('div');
			container.className = 'image';
			container.appendChild(this.images[i]);
			
			$(this._element.selector +' .images')[0].appendChild(container);
		
		}
		
		$(this._element.selector +' .images .image').each(function(index) {
			$(this).hide();
		});
		
		$(this._element.selector +' .images').show();
		
		$(this._element.selector +' .box').fadeIn();
		
		//Initiate a new content object.
		this.content = new this.content($(this._element.selector +' .content'), this._content);
		ctx.content.show();
		
		//Initiate a new pager object
		this.pager = new this.pager($(this._element.selector +' .pager'), {size: this.images.length});	
		ctx.pager.show();
		
		//Set the active image.
		this.active = this.setActive(0, true, function() {
			
			//Setup event handling
			$(ctx._element.selector +' .pager li a').click(function(event) {
				
				if (ctx.busy == false) {
					
					var sudoactive = parseInt($(this).attr('rel'));
					
					if (ctx.active != sudoactive) {
						ctx.goTo(parseInt(sudoactive));
					}
					
				}
				
				event.preventDefault();
				
			});
			
			$(document).bind('keyup', function(event) {
				
				if (ctx.busy == false) {
				
					if (event.keyCode == 39)
						ctx.next();
					
					if (event.keyCode == 37)
						ctx.previous();
					
				}
				
				event.preventDefault();
				
			});
			
			ctx.start();
			
		});
		
	},
	
	/***********************************
	
	Transition Methods
	
	***********************************/
	
	goTo: function(index, event) {
		
		ctx = this;
		
		this.pause();
		
		if (typeof(this.pager) != 'undefined')
			this.pager.setActive(index);
			
		if (typeof(this.content) != 'undefined')
			this.content.setActive(index);
		
		this.resignActive(this.active, true, function() {
			ctx.active = ctx.setActive(index, true, function() {
				ctx.start();
			});
		});
		
		if (event)
			event.preventDefault();
		
	},
	
	next: function(event) {
		
		ctx = this;
		
		this.pause();
		
		var next = this.active + 1;
		
		if (this.active == this.images.length - 1)
			next = 0;
		
		if (typeof(this.pager) != 'undefined')
			this.pager.setActive(next);
			
		if (typeof(this.content) != 'undefined')
			this.content.setActive(next);
		
		this.resignActive(this.active, true, function() {
			ctx.active = ctx.setActive(next, true, function() {
				ctx.start();
			});
		});
		
		if(event)
			event.preventDefault();
		
	},
	
	previous: function(event) {
		
		ctx = this;
		
		this.pause();
		
		var previous = this.active - 1;
		
		if(this.active == 0)
			previous = this.images.length - 1;
		
		if (typeof(this.pager) != 'undefined')
			this.pager.setActive(previous);
		
		if (typeof(this.content) != 'undefined')
			this.content.setActive(previous);
		
		this.resignActive(this.active, true, function() {
			ctx.active = ctx.setActive(previous, true, function() {
				ctx.start();
			});
		});
		
		if(event)
			event.preventDefault();
		
	},
	
	autoTransition: function(busy) {
		
		this.busy = busy;
		
		//This could be simplified with the use of the jQuery.proxy in 1.4, but Drupal 6 doesn't like jQuery 1.4 so we have to do this.
		var ctx = this;
		
		if(busy == false) {
			this.timer = setTimeout(function() { ctx.next(); }, this._speed);
		} else {
			clearTimeout(this.timer);
		}
		
	},
	
	pause: function() {
		
		this.autoTransition(true);
		
	},
	
	start: function() {
		
		this.autoTransition(false);
		
	},
	
	setActive: function(index, fade, callback) {
		
		if (typeof(this.pager) != 'undefined')
			this.pager.setActive(index);
		
		if (typeof(this.content) != 'undefined')
			this.content.setActive(index);
		
		if(fade) {
			$(this._element.selector +' .images .image').eq(index).fadeIn(1000, callback);
		} else {
			$(this._element.selector +' .images .image').eq(index).show();
			callback.call();
		}
		
		return index;
		
	},
	
	resignActive: function(index, fade, callback) {
		
		if (typeof(this.pager) != 'undefined')
			this.pager.resignActive(index);
		
		if (typeof(this.content) != 'undefined')
			this.content.resignActive(index);
		
		if(fade) {
			$(this._element.selector +' .images .image').eq(index).fadeOut(1000, callback);
		} else {
			$(this._element.selector +' .images .image').eq(index).hide();
			callback.call();
		}
		
	},
	
	/***********************************
	
	Loading Methods
	
	***********************************/
	
	load: function(_image) {
		
		if (img != 'undefined')
			var img = new Image();
			
		img.src = _image;
		this.images.push(img);
		
		ctx = this;
		img.onload = function() {
			ctx.loaded(img);
		}
		
	},
	
	loaded: function(img) {
		
		ctx = this;
			
		this.loadCount++;
		
		//After the first one is loaded, lets show it.
		
		if (this.loadCount < this._content.length) {
		    this.loading.setMessage('Loading '+ this.loadCount +' of '+ this._content.length);
		} else {
			this.loading.setMessage('Loading Complete');
		    this.loading.hide({
		    	callback: function() { ctx.startEngine(); },
		    	delay: 600
		    });
		}
		
	},
		
	/***********************************
	
	Loading Display Object
	
	***********************************/
	
	loading: Class.make({
		
		initialize: function(element, options) {
			
			if (typeof(options) == 'undefined')
				throw('Exception: No options object found in mBanner.loader');
				
			this.element = element;
			
		},
		
		setMessage: function(message) {
			
			$(this.element.selector +' .message').html(message);
			
		},
		
		show: function() {
			
			$(this.element).show();
			
		},
		
		hide: function(options) {
		
			if (typeof(options) == 'undefined')
				throw('Exception: No options object found in mBanner.loading.hide');
			
			loadingctx = this;
			
			window.setTimeout(function() {
			    
			    $(loadingctx.element.selector +' .message').animate({
				    left: '-=120'
				}, 1000, 'swing');
			    
			    $(loadingctx.element).fadeOut(1000, function() { options.callback.call(); });
			
			}, options.delay);
			
		}
		
	}),
	
	/***********************************
	
	Content Object
	
	***********************************/
	
	content: Class.make({
		
		initialize: function(element, content) {
				
			if (typeof(content) == 'undefined')
				throw('Exception: No text object found in mBanner.content');
			
			this.element = element;
			
			container = document.createElement('div');
			container.className = 'sections';
			
			for (i = 0; i < content.length; i++) {
				section = document.createElement('div');
				section.className = 'section '+ i;
				
				sectiontitle = document.createElement('div');
				sectiontitle.className = 'title';
				sectiontitle.innerHTML = content[i].title;
				
				sectiontext = document.createElement('div');
				sectiontext.className = 'text';
				sectiontext.innerHTML = content[i].message;
				
				section.appendChild(sectiontitle);
				section.appendChild(sectiontext);
				container.appendChild(section);
			}
			
			this.hide();
			$(element).append(container);
			
		},
		
		setActive: function(index) {
			
			$(this.element.selector +' div.section.'+ index).addClass('active');
			
		},
		
		resignActive: function(index) {
			
			$(this.element.selector +' div.section.'+ index).removeClass('active');
			
		},
		
		show: function() {
			
			$(this.element).show();
			
		},
		
		hide: function() {
			
			$(this.element).hide();
			
		}
		
	}),
	
	/***********************************
	
	Pager Object
	
	***********************************/
	
	pager: Class.make({
		
		initialize: function(element, options) {
			
			if (typeof(options) == 'undefined')
				throw('Exception: No options object found in mBanner.pager');
			
			this.element = element;
			
			container = document.createElement('ul');
			
			for (i = 0; i < options.size; i++) {
				li = document.createElement('li');
				a = document.createElement('a');
				a.href = "#";
				a.rel = i;
				a.innerHTML = i + 1;
				
				li.appendChild(a);
				container.appendChild(li);
			}
			
			this.hide();
			$(element).append(container);
			
		},
		
		setActive: function(index) {
			
			$(this.element.selector +' li a[rel='+ index +']').addClass('active');
			
		},
		
		resignActive: function(index) {
			
			$(this.element.selector +' li a[rel='+ index +']').removeClass('active');
			
		},
		
		show: function() {
			
			$(this.element).show();
			
		},
		
		hide: function() {
			
			$(this.element).hide();
			
		}
		
	})
	
});

$.fn.mBanner = function(_content, _speed) {
	
	var _element = $(this);
	new mBanner(_element, _content, _speed);
	
};

})(jQuery);