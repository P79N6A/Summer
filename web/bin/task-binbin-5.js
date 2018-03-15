var sum=0;//统计当前节点的个数

window.onload=function(){   //页面加载完毕后给各按钮以及队列中元素绑定事件
    document.getElementById("left-in").onclick=leftIn;
    document.getElementById("left-out").onclick=leftOut;
    document.getElementById("right-in").onclick=rightIn;
    document.getElementById("right-out").onclick=rightOut;
    document.getElementById("bubble-sort").onclick=bubbleSort;
    document.getElementById("random-array").onclick=randomArray;
    document.getElementById("quene").onclick=clickDelete;//该"点击事件"触发会删除队列中的元素，为了优化性能，采用的是事件代理的办法，将事件绑定到队列的容器
}

function checkInput(){  //针对用户的输入进行检查，如果不是合法的数就会弹框警告
    var input=document.getElementById("number-input").value;
    if(input==""){
        alert("非法输入！");
        return false;
    }
    document.getElementById("number-input").value="";//清空文本框
    if(isNaN(Number(input))){
        alert("非法输入！");
        return false;
    }else if((Number(input)>=10)&&(Number(input)<=100)){
        return Number(input);
    }else{
        alert("输入值不在10~100之间！");
        return false;
    }
}

function leftIn(){  //处理左边插入值的情况
    if(sum>=60){
        alert("已达到最大数量：60！无法添加。");
        return;
    }
    var input=checkInput();
    var quene=document.getElementById("quene");
    if(input!=false){
        var tmp=document.createElement("div");
        var first=quene.firstElementChild;//找到队列的第一个元素
        tmp.className="sub-block";
        tmp.title=input;
        tmp.style.height=(input*3).toString()+"px";
        quene.insertBefore(tmp,first);//将新的div插入到第一个元素前面
        sum++;
    }
}

function leftOut(){ //处理左边删除值的情况
    var deleteThisNode=document.getElementById("quene").firstElementChild;//找到第一个元素
    if(deleteThisNode==undefined){
        alert("不存在可删除的节点！");
    }else{
        deleteNode(deleteThisNode);//调用deleteNode过程来删除对应节点
    }
}

function rightIn(){ //处理右边插入值的情况
    if(sum>=60){
        alert("已达到最大数量：60！无法添加。");
        return;
    }
    var input=checkInput();
    var quene=document.getElementById("quene");
    if(input!=false){
        var tmp=document.createElement("div");
        tmp.className="sub-block";
        tmp.title=input;
        tmp.style.height=(input*3).toString()+"px";
        quene.appendChild(tmp);
        sum++;
    }
}

function rightOut(){ //处理右边删除值的情况
    var deleteThisNode=document.getElementById("quene").lastElementChild;//找到最后一个元素
    if(deleteThisNode==undefined){
        alert("不存在可删除的节点！");
    }else{
        deleteNode(deleteThisNode);//调用deleteNode过程来删除对应节点
    }
}

function clickDelete(ev){   //处理"点击容器中元素"事件，采用的是事件代理的办法，将事件绑定到父元素容器上，删除节点调用了deleteNode过程
    var ev = ev || window.event;
    var target = ev.target || ev.srcElement;
    if(target.className=="sub-block"){
        deleteNode(target);
    }
}

function deleteNode(obj){   //该过程用于删除参数中指定的节点
    var del=obj.parentNode.removeChild(obj);
    alert("出队列的节点："+del.title);
    sum--;        
}



function bubbleSort(){//冒泡排序，为了清晰显示该过程，改写成setTimeout的形式
    var ii=0,jj=0;
    setTimeout(sortStep,300);

    function sortStep(){
        var div1,div2;
        if(jj<sum-1-ii){
            div1=document.getElementById("quene").childNodes[jj];
            div2=document.getElementById("quene").childNodes[jj+1];
            if(parseFloat(div1.title)>parseFloat(div2.title)){
                exchange(div1,div2);
            }
            ++jj;
        }else{
            jj=0;
            ii++;
        }
        if(ii<sum-1){
            setTimeout(sortStep,300);
        }
    }
}


function exchange(div1,div2){//冒泡排序的子过程，用于交换两个值
    var tmp;

    tmp=div1.style.height;
    div1.style.height=div2.style.height;
    div2.style.height=tmp;

    tmp=div1.title;
    div1.title=div2.title;
    div2.title=tmp;
}

function randomArray(){//随机生成10个数并插入到队列中，要生成更多的数重复调用即可
    for(var i=0;i<10;++i){
        if(sum>=60){
            break;
        }
        var rand=Math.round(Math.random()*90+10);
        var tmp=document.createElement("div");
        tmp.className="sub-block";
        tmp.title=rand;
        tmp.style.height=(rand*3).toString()+"px";
        quene.appendChild(tmp);//将新的div插入到第一个元素前面
        sum++;
    }
    alert("已经向队列中随机生成"+i+"个元素，可重复添加！");
    if(sum>=60){
        alert("队列已满！");
    }
}
