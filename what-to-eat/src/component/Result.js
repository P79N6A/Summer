import React,{Component} from 'react';
import { Button } from 'antd';
import { Card } from 'antd';
import { Tag } from 'antd';
import 'antd/dist/antd.css';

class Result extends Component{
    constructor (props) {
        super(props);
        this.state ={
            name: null
        };
    };

    componentDidMount () {
        var list =localStorage.getItem('list').split(',');
        var randomIndex = Math.floor(list.length * Math.random());
        this.setState({
            name:list[randomIndex]
        });
    };

    render () {
        return (
            <Card title="最后结果为..."  style={{ width: 300 }}>
                <Tag color="green">{this.state.name}</Tag>
                <Button type="dashed" onClick = {this.props.rollAgain} >要不，还是换一家吧😓</Button>
            </Card>
        );
    }
};

export default Result;