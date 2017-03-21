var FloatLayer={
    instance:null,
    init:function(){
        this.instance=flSingle();
        this.instance.style.display="none";
    },
    show:function(){
        this.instance.style.display="block";
    },
    hide:function(){
        this.instance.style.display="none";
    }
}

$("#display").onclick=function(){
    if(FloatLayer.instance==null){
        FloatLayer.init();
    }
    FloatLayer.show();
}