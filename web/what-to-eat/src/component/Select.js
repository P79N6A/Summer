import React,{Component} from 'react';
import { Card } from 'antd';
import { Button } from 'antd';
import { Tag } from 'antd';
import { Spin } from 'antd';
import 'antd/dist/antd.css';

class Select extends Component{
    constructor (props) {
        super(props);
        this.state ={
            already: false,
            isSup:false,//是否支持localStorage存储
            list:[]
        };
    };
    componentDidMount () {
        setTimeout(()=>{
            this.setState({
                already: true
            });
        },500);
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
    render () {
        if(!this.state.already) {
            return <Spin size="large" />;
        }
        if(this.state.isSup) {
            return (
                <Card  title="这些是已选的...">
                    <div>
                        {this.state.list.map(item => {return <Tag color="pink" key={item}>{item}</Tag>;})}
                    </div>
                    <Button type="primary" onClick = {this.props.getResult}>Roll吧！</Button>
                    <Button type="dashed" onClick = {this.props.addOption}>我要添加！</Button>
                </Card>
            );
        } else {
            return (
                <div>LocalStorage都不支持，你用的是小霸王吧？</div>
            );
        }
    }
};

export default Select;