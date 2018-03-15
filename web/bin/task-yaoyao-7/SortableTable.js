function SortableTable(element,data,tableHead,index,style){
    this.element=element;
    this.data=data;
    this.tableHead=tableHead;
    this.index=index;
    this.style=style;
    this.sortFlag="inc";//inc表示升序，dec表示降序
}

SortableTable.prototype.init=function(){}

SortableTable.prototype.sort=function(keyValue){
    that=this;
    
    var index=this.tableHead.indexOf(keyValue);
    switch(this.sortFlag){
        case "inc":this.data.sort(function(a,b){
            return a[index]-b[index];
        });break;
        case "dec":this.data.sort(function(a,b){
            return b[index]-a[index];
        });break;
        default:;
    }
    toggle();

    function toggle(){
        if(that.sortFlag=="inc"){
            that.sortFlag="dec";
        }else{
            that.sortFlag="inc";
        }
    }

}

SortableTable.prototype.addNode=function(){}

SortableTable.prototype.deleteNode=function(){}

SortableTable.prototype.render=function(){
    that=this;
    this.element.innerHTML="";

    var table=document.createElement("table");
    this.element.appendChild(table);

    var tr=document.createElement("tr");
    table.appendChild(tr);
    tr.onclick=function(ev){
        var ev = ev || window.event;
        var target = ev.target || ev.srcElement;
        if((target.nodeName.toLowerCase() == 'th')&&(that.index.indexOf(target.innerHTML)!=-1)){
            that.sort(target.innerHTML);
            that.render();
        }
    }

    for(var i=0;i<tableHead.length;++i){
        var th=document.createElement("th");
        th.innerHTML=tableHead[i];
        if(this.index.indexOf(this.tableHead[i])!=-1){
            th.classList.add(that.style.sortableColumn);
        }
        th.classList.add(that.style.tableHead);
        tr.appendChild(th);
    }

    for(var i=0;i<data.length;++i){
        var tr=document.createElement("tr");
    
        for(var j=0;j<data[i].length;++j){
            var td=document.createElement("td");
            td.innerHTML=data[i][j];
            tr.appendChild(td);
        }

        if(i%2==0){
            tr.className=that.style.tableRowEven;
        }else{
            tr.className=that.style.tableRowOdd;
        }
        table.appendChild(tr);
    }
}