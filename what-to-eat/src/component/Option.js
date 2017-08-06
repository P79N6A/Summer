import React,{Component} from 'react';
import { Card } from 'antd';
import { Button } from 'antd';
import { Tag } from 'antd';
import { Input } from 'antd';
import 'antd/dist/antd.css';

class Select extends Component{
    constructor (props) {
        super(props);
        this.state ={
            text:'',
            isSup:false,//是否支持localStorage存储
            list:[]
        };
    };
    componentDidMount () {
        if (!!window.localStorage) {
            this.setState({
                isSup:true
            });
            if (localStorage.getItem('list')) {
                this.setState({
                    list:localStorage.getItem('list').split(',')
                });
            }
        }
    };

    deleteItem (item) {
        var list=this.state.list;
        this.setState({
            list:list.slice(0,list.indexOf(item)).concat(list.slice(list.indexOf(item)+1,list.length))
        });
    };

    syncInput (event) {
        this.setState({
            text:event.target.value
        });
    };

    addNew (event) {
        if(this.state.text!==''){
            this.setState({
                text:'',
                list:this.state.list.concat(this.state.text)
            });   
        }
    };

    save () {
        var list = this.state.list;
        localStorage.setItem('list',list.join(','));
        this.props.submitAdd();
    };

    render () {
        return (
            <Card title="在这里进行修改..."  style={{ width: 300 }}>
                <div>
                    {this.state.list.map(item => {return <Tag closable onClose={()=>{this.deleteItem(item)}} color="pink" key={item}>{item}</Tag>;})}
                </div>
                <Input ref="inputArea" onChange={this.syncInput.bind(this)} placeholder="想吃别的，添加到这吧！" />
                <Button type="primary" icon="plus" onClick = {this.addNew.bind(this)}>加入！</Button>
                <Button type="primary" icon="save" onClick = {this.save.bind(this)}>保存！</Button>
            </Card>
        );
    }
};

export default Select;