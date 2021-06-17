
function initMap() {
  
    var map = new google.maps.Map(document.getElementById('map'), {
        zoom: 12,
        center: {lat: 23.621901, lng: 119.513175 },
        mapTypeId: google.maps.MapTypeId.ROADMAP
    });

    var Pos = [];
    Pos[0] = new google.maps.LatLng(23.655144, 119.519782);	//鯨魚洞
    Pos[1] = new google.maps.LatLng(23.603957, 119.502507);	//池西岩瀑
    Pos[2] = new google.maps.LatLng(23.573785, 119.514057);	//牛心山
    Pos[3] = new google.maps.LatLng(23.595438, 119.516369);	//大果葉玄武岩
    Pos[4] = new google.maps.LatLng(23.597414, 119.514814);	//三石壁
    Pos[5] = new google.maps.LatLng(23.610599, 119.518903);	//二崁柱狀玄武岩



    var pos1 = [23.655144,119.519782];
    //var Title = [ '鯨魚洞', '池西岩瀑', '牛心山', '大果葉玄武岩', '三石壁', '二崁柱狀玄武岩'];

   /* var secretMessages = [];
    secretMessages[0] = '';					
    secretMessages[1] = '';
    secretMessages[2] = '';
    secretMessages[3] = '';
    secretMessages[4] = '';
    secretMessages[5] = '';			*/
 	
   //callback           
    attachSecretMessage(null, '');
     var dynamicMarker;
    
    
     
  /*  for (var i = 0; i < secretMessages.length; ++i) {
        var marker = new google.maps.Marker({
            position: Pos[i],		
            map: map,
            title: Title[i]
        });
        attachSecretMessage(marker, secretMessages[i]);
    }*/

   
      
    function attachSecretMessage(markers, secretMessage) {
        
            var marker = new google.maps.Marker({
                position: new google.maps.LatLng(pos1[0],pos1[1]),		
                map: map,
                title: 'None'
            });
        var lLoffset= new google.maps.LatLng(pos1[0]+0.025 ,pos1[1]+0.025);	
     var infoBubble;
            url_content("Resources/InWindowMessages.html").success(
                function(data){ 
                    infoBubble = new InfoBubble({
                        map: map,
                        content: data,
                        position:lLoffset,
                        shadowStyle: 0,
                        padding: 0,
                        backgroundColor: '#0d1e1e1e',
                        height : 150,
                        width:150,
                        borderRadius: 0,
                        arrowSize: 0,
                        borderWidth: 0,
                        borderColor: '#2c2c2c',
                        disableAutoPan: true,
                        hideCloseButton: true,
                        arrowPosition: 30,
                        backgroundClassName: 'transparent',
                        arrowStyle: 2,
                  });

        });
        
            marker.addListener('mouseover',  function() {
               
              
              infoBubble.open();
               // infowindow.open(marker.get('map'), marker);   
          });
          marker.addListener('mouseout', function() {
            infoBubble.close();


            
        });
            marker.addListener('click',
             function() {
               
                url_content("Resources/InWindowMessages.html").success(
                   
                    function(data){ 

                        infowindow.content =data;
                infowindow.open(marker.get('map'), marker);   

            });
          


          });  
      
          dynamicMarker = marker ;
    }
    class USGSOverlay extends google.maps.OverlayView {
        bounds;
        image;
        div;
        constructor(bounds, image) {
          super();
          this.bounds = bounds;
          this.image = image;
        }
        /**
         * onAdd is called when the map's panes are ready and the overlay has been
         * added to the map.
         */
        onAdd() {
          this.div = document.createElement("div");
          this.div.style.borderStyle = "none";
          this.div.style.borderWidth = "0px";
          this.div.style.position = "absolute";
          // Create the img element and attach it to the div.
          const img = document.createElement("img");
          img.src = this.image;
          img.style.width = "100%";
          img.style.height = "100%";
          img.style.position = "absolute";
          this.div.appendChild(img);
          // Add the element to the "overlayLayer" pane.
          const panes = this.getPanes();
          panes.overlayLayer.appendChild(this.div);
        }
        draw() {
          // We use the south-west and north-east
          // coordinates of the overlay to peg it to the correct position and size.
          // To do this, we need to retrieve the projection from the overlay.
          const overlayProjection = this.getProjection();
          // Retrieve the south-west and north-east coordinates of this overlay
          // in LatLngs and convert them to pixel coordinates.
          // We'll use these coordinates to resize the div.
          const sw = overlayProjection.fromLatLngToDivPixel(
            this.bounds.getSouthWest()
          );
          const ne = overlayProjection.fromLatLngToDivPixel(
            this.bounds.getNorthEast()
          );
    
          // Resize the image's div to fit the indicated dimensions.
          if (this.div) {
            this.div.style.left = sw.x + "px";
            this.div.style.top = ne.y + "px";
            this.div.style.width = ne.x - sw.x + "px";
            this.div.style.height = sw.y - ne.y + "px";
          }
        }
        /**
         * The onRemove() method will be called automatically from the API if
         * we ever set the overlay's map property to 'null'.
         */
        onRemove() {
          if (this.div) {
            this.div.parentNode.removeChild(this.div);
            delete this.div;
          }
        }
        /**
         *  Set the visibility to 'hidden' or 'visible'.
         */
        hide() {
          if (this.div) {
            this.div.style.visibility = "hidden";
          }
        }
        show() {
          if (this.div) {
            this.div.style.visibility = "visible";
          }
        }
        toggle() {
          if (this.div) {
            if (this.div.style.visibility === "hidden") {
              this.show();
            } else {
              this.hide();
            }
          }
        }
        toggleDOM(map) {
          if (this.getMap()) {
            this.setMap(null);
          } else {
            this.setMap(map);
          }
        }
      }
    




    function url_content(url){
        return $.get(url);
    }
    function getRandomInt(max) {
        return Math.floor(Math.random() * max);
      }
      
    function sleep(ms) {
        return new Promise((resolve) => {
          setTimeout(resolve, ms);
        });
      }
}
