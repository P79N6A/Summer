function $(selector,parent){//自己编写的一个选择器
    if(parent==undefined){
        parent=document;
    }
    if(String(selector)[0]=="#"){
        return parent.getElementById(String(selector).substring(1));
    }else if(String(selector)[0]=="."){
        return parent.getElementsByClassName(String(selector).substring(1));
    }else{
        return parent.getElementsByTagName(String(selector).substring(0));
    }
}   

function $new(tagName){//产生一个新标签
    return document.createElement(tagName);
}