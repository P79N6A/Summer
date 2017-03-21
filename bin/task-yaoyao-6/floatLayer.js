var getSingle=function(fn){
    var result;
    return function(){
        if(!result){
            result=fn.apply(this,arguments);
            $("body")[0].appendChild(result);
        }
        return result;
    }
}

var Drag=function(){
    var initX,initY,moveX,moveY,flag=false;
    return {
        getFlag:function(){
            return flag;
        },
        toggleflag:function(event){
            if(flag==false){
                flag=true;
            }else{
                flag=false;
            }
        },
        setStart:function(event){
            initX=event.clientX;
            initY=event.clientY;
        },
        setEnd:function(event){
            moveX=event.clientX;
            moveY=event.clientY;
        },
        getOffset:function(){
            return [moveX-initX,moveY-initY];
        }

    }
}

var buildFloatLayer=function(){
    var flMask=$new("div");
    var drag=Drag();
    flMask.className="fl-mask";
    flMask.onclick=function(event){
        if(event.target.className=="fl-mask"){
            flMask.style.display="none";
        }
    }

    var flWindow=$new("div");
    flWindow.className="fl-window";
    flWindow.style.left=window.innerWidth*0.5+"px",
    flWindow.style.top=window.innerHeight*0.5+"px",
    flMask.appendChild(flWindow);

    var flHeader=$new("div");
    flHeader.className="fl-header";
    flHeader.innerText="This is a Float Layer!";
    flHeader.onmousedown=function(event){
        event.stopPropagation();
        //拖动开始
        drag.toggleflag(event);
        drag.setStart(event);
    }
    flHeader.onmousemove=function(event){
        event.stopPropagation();
        if(drag.getFlag()){
            drag.setEnd(event);
            var offset=drag.getOffset();
            flWindow.style.left=(Number(flWindow.style.left.slice(0,-2))+offset[0])+"px";
            flWindow.style.top=(Number(flWindow.style.top.slice(0,-2))+offset[1])+"px";
            drag.setStart(event);
        }
    }
    flHeader.onmouseup=function(){
        event.stopPropagation();
        //拖动释放
        drag.toggleflag();
    }


    var flContent=$new("div");
    flContent.className="fl-content";
    var midSpan=$new("span");
    midSpan.innerText="This is a Float Layer!";
    flContent.appendChild(midSpan);

    var flFooter=$new("div");
    flFooter.className="fl-footer";
    var okBtn=$new("input");
    okBtn.type="button";
    okBtn.className="btn";
    okBtn.id="ok";
    okBtn.value="OK";
    okBtn.onclick=function(){
        event.stopPropagation();
        alert("Click OK!");
    }
    var cancelBtn=$new("input");
    cancelBtn.type="button";
    cancelBtn.className="btn";
    cancelBtn.id="cancel";
    cancelBtn.value="Cancel";
    cancelBtn.onclick=function(event){
        event.stopPropagation();
        flMask.style.display="none";
    }
    flFooter.appendChild(okBtn);
    flFooter.appendChild(cancelBtn);

    flWindow.appendChild(flHeader);
    flWindow.appendChild(flContent);
    flWindow.appendChild(flFooter);

    return flMask;
}

var flSingle=getSingle(buildFloatLayer);//调用flSingle产生唯一的一个浮出层实例并返回